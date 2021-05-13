/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:43:53 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/22 10:39:08 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*src1;
	int		i;

	i = 0;
	src1 = (char *)src;
	while (src[i])
		i++;
	if (size != 0)
	{
		size -= 1;
		while ((*src1) && size--)
			*dst++ = *src1++;
		if (*dst)
			*dst = '\0';
	}
	return (i);
}
