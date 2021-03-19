/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 21:46:00 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/08/23 18:12:55 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnchar(const char *str, char c)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (str[i] == c)
				return (1);
	return (0);
}

int		ft_strlen_2d(char **str)
{
        int     i;
        i = 0;
        while (str && str[i] != NULL)
            i++;
        return (i);
}

int		free_2d(char **str)
{
        int             i;

        i = 0;
        while (str[i] != NULL)
                free(str[i++]);
        free(str);
        return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1))
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	else
		return (0);
}