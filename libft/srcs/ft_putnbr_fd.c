/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:13:16 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/02/25 16:54:25 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 *= -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
	else
		ft_putchar_fd(n1 + 48, fd);
}

void	ft_putnbr_fd2(float n, int fd)
{
	double	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 *= -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd2(n1 / 10, fd);
		ft_putnbr_fd2((int)n1 % 10, fd);
	}
	else
		ft_putchar_fd(n1 + 48, fd);
}
