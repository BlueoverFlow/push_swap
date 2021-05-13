/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:36:10 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/22 11:23:26 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;
	size_t				i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (src == NULL && dst == NULL)
		return (NULL);
	if (src1 < dst1)
		while (++i <= len)
			dst1[len - i] = src1[len - i];
	else
		while (len-- > 0)
			*(dst1++) = *(src1++);
	return (dst);
}
