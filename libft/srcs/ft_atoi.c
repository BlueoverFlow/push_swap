/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:06:02 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/04 13:31:10 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long int	ft_atoi(const char *str)
{
	int			a;
	int			b;
	long int	c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n'
		|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '-')
		b = -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] <= '9' && str[a] >= '0')
	{
		c = c * 10;
		c = c + (str[a] - 48);
		a++;
		if ((c * b) > 2147483647)
			return (2147483649);
		else if ((c * b) < -2147483648)
			return (2147483649);
	}
	return ((int)(c * b));
}
