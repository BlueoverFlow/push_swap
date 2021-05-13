/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:12:08 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/21 15:51:17 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	int		start;
	size_t	count;

	count = 1;
	start = 0;
	while (s[start])
	{
		while (s[start] && c == s[start])
			start++;
		if (s[start])
			count++;
		while (s[start] && c != s[start])
			start++;
	}
	return (count);
}

static char	**ft_koalloc(char **ptr, size_t i)
{
	i += 1;
	while (ptr[--i] != NULL)
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

static char	**ft_split2(char const *s, char c, char **ptr, size_t cw)
{
	size_t	i;
	int		start;
	int		len;

	i = -1;
	start = 0;
	len = 0;
	while (s[start] && ++i < cw - 1)
	{
		while (s[start] == c && s[start])
			start++;
		while (s[start] != c && s[start])
		{
			start++;
			len++;
		}
		start -= len;
		ptr[i] = ft_calloc(len + 1, sizeof(char));
		if (!ptr[i])
			return (ft_koalloc(ptr, i));
		ft_memcpy(ptr[i], s + start, len);
		start += len;
		len = 0;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char		**ptr;
	size_t		cw;

	if (s == NULL)
		return (NULL);
	cw = ft_countwords(s, c);
	ptr = (char **)malloc(sizeof(char *) * cw);
	if (!ptr)
		return (NULL);
	ptr[cw - 1] = NULL;
	return (ft_split2(s, c, ptr, cw));
}
