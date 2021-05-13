/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:40:41 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/21 18:58:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s && f)
	{
		ptr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (!ptr)
			return (NULL);
		while (s[i])
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
