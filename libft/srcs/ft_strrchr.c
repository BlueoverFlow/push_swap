/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:41:31 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/23 15:45:36 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;

	a = ft_strlen(s) + 1;
	while (s[--a] != (char)c)
		if (a == 0)
			return (NULL);
	return ((char *)s + a);
}
