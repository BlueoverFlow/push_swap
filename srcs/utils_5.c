/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:22:02 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 09:55:23 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_instr(int instr, int pres)
{
	if (pres == 0)
		ft_putstr_fd("sa\n", 1);
	if (pres == 1)
		ft_putstr_fd("sa\n", 1);
	if (pres == 2)
		ft_putstr_fd("pa\n", 1);
	if (pres == 3)
		ft_putstr_fd("pb\n", 1);
	if (pres == 4)
		ft_putstr_fd("ra\n", 1);
	if (pres == 5)
		ft_putstr_fd("rb\n", 1);
	if (pres == 6)
		ft_putstr_fd("rra\n", 1);
	if (pres == 7)
		ft_putstr_fd("rrb\n", 1);
	if (pres == 8)
		ft_putstr_fd("ss\n", 1);
	if (pres == 9)
		ft_putstr_fd("rr\n", 1);
	if (pres == 10)
		ft_putstr_fd("rrr\n", 1);
}

void	norm_1(t_stack **stack, t_stack **extra, int s)
{
	if (s == 1)
		print_instr(rr(stack), 6);
	else if (s == 2)
		print_instr(rr(stack), 7);
	else
		print_instr(both(stack, extra, 3), 10);
}

void	norm_3(t_wheel *wheel, t_stack *a, int *index)
{
	int	i;

	i = 0;
	while (++i < wheel->l_a)
	{
		if (index[i] == wheel->smaller)
			if (lst_elem(a, i) < lst_elem(a, wheel->top))
				wheel->top = i;
		if (index[i] < wheel->smaller)
		{
			wheel->smaller = index[i];
			wheel->top = i;
		}
	}
}

void	_toping(t_stack **stack, t_stack **extra, int data, int s)
{
	int		i;
	int		l;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	l = lstsize2(*stack);
	i = lst_order(*stack, data);
	while ((*stack)->data != data)
	{
		if (i <= l / 2)
		{
			if (s == 1)
				print_instr(r(stack), 4);
			else if (s == 2)
				print_instr(r(stack), 5);
			else
				print_instr(both(stack, extra, 2), 9);
		}
		else
			norm_1(stack, extra, s);
	}
}
