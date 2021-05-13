/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:23:14 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/24 10:05:43 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	if (dst == NULL && src && size == 0)
		return (ft_strlen(src));
	c = ft_strlen(src);
	a = ft_strlen(dst);
	if (size <= a)
		return (c + size);
	b = 0;
	d = a;
	while (src[b] && d < size - 1)
		dst[d++] = src[b++];
	dst[d] = '\0';
	return (a + c);
}
