/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:56:41 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:29:44 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*get_line(char **buffer)
{
	char		*reader;
	char		*newline;
	char		*tmp;

	reader = ft_strchr2(*buffer, '\n');
	tmp = NULL;
	if (reader)
	{
		if (!(newline = ft_strndup2(*buffer, reader - *buffer)))
			return (NULL);
		tmp = *buffer;
		if (!(*buffer = ft_strdup2(reader + 1)))
			return (NULL);
	}
	else if (!(newline = ft_strdup2(*buffer)))
		return (NULL);
	if (!tmp)
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(tmp);
	tmp = 0;
	return (newline);
}

int			get_buffer(char **buffer, char *reader, int fd, int *ret)
{
	char	*oldbuffer;

	while (!(ft_strchr2(*buffer, '\n')) && *ret)
	{
		*ret = read(fd, reader, BUFFER_SIZE);
		if (*ret)
		{
			reader[*ret] = '\0';
			oldbuffer = *buffer;
			if (!(*buffer = ft_strjoin2(*buffer, reader)))
				return (0);
			free(oldbuffer);
			oldbuffer = NULL;
		}
	}
	free(reader);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*reader;
	static char	*buffer = NULL;
	int			ret;

	ret = 1;
	if ((read(fd, NULL, 0) != 0 || fd < 0 || BUFFER_SIZE >= 2147483647 ||
		BUFFER_SIZE < 0 || !(reader = malloc(BUFFER_SIZE + 1))))
		return (-1);
	if (!(get_buffer(&buffer, reader, fd, &ret)))
		return (-1);
	if (buffer)
	{
		if (!(*line = get_line(&buffer)))
			return (-1);
		if (ret)
			return (1);
		else
			return (0);
	}
	*line = ft_strdup2("");
	return (0);
}
