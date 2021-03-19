/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:23:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/21 18:55:05 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_n_isnegative(int n)
{
	char			*ptr;
	unsigned int	d;
	unsigned int	n1;
	size_t			count;

	n *= -1;
	d = n;
	n1 = n;
	count = 0;
	while (d != 0)
	{
		d /= 10;
		count++;
	}
	if (count == 0)
		count++;
	if (!(ptr = ft_calloc(count + 2, sizeof(char))))
		return (NULL);
	ptr[0] = '-';
	while (count--)
	{
		ptr[count + 1] = (n1 % 10) + 48;
		n1 /= 10;
	}
	return (ptr);
}

char		*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	d;
	unsigned int	n1;
	size_t			count;

	if (n < 0)
		return (ft_n_isnegative(n));
	d = n;
	n1 = n;
	count = 0;
	while (d != 0)
	{
		d /= 10;
		count++;
	}
	if (count == 0)
		count++;
	if (!(ptr = ft_calloc(count + 1, sizeof(char))))
		return (NULL);
	while (count--)
	{
		ptr[count] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (ptr);
}
