/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:55:30 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/03 10:55:45 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	_init_var(t_wheel *wheel, t_stack *a, t_stack *b)
{
	wheel->top_a = 0;
	wheel->top_b = 0;
	wheel->preaxe = 0;
	wheel->l_a = quicksort(a, &(wheel->buffer_a));
}

static void	norm_2(t_stack **a, t_stack **b, t_wheel wheel)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		_toping(a, b, wheel.buffer_a[i], 1);
		print_instr(p(a, b), 3);
	}
}

static void	is_few_param(t_stack **a, t_stack **b, t_checker c, t_wheel wheel)
{
	if (c.argc <= 6)
	{
		if (c.argc > 4)
			norm_2(a, b, wheel);
		if ((*a)->next && (*a)->data > (*a)->next->data)
			print_instr(s(a), 1);
		if ((*a)->next->next && (*a)->next->next->data < (*a)->data)
			print_instr(rr(a), 6);
		else if ((*a)->next->next && (*a)->next->next->data < (*a)->next->data)
		{
			print_instr(rr(a), 6);
			print_instr(s(a), 1);
		}
		while (b && *b)
			print_instr(p(b, a), 2);
		out(3);
	}
}

void	sort(t_stack **a, t_stack **b, t_checker checker)
{
	t_wheel	wheel;
	int		top;
	int		*data;

	_init_var(&wheel, *a, *b);
	is_few_param(a, b, checker, wheel);
	free(wheel.buffer_a);
	while (lstsize2(*a))
	{
		top = s_scan(*a, *b, wheel, &(wheel.similarity));
		while (--(wheel.similarity) > -1)
			_toping(a, b, top, 3);
		_toping(a, b, top, 1);
		_toping(b, a, find_preaxe(*b, top), 2);
		print_instr(p(a, b), 3);
	}
	wheel.l_b = quicksort(*b, &data) + 1;
	while (b && *b && --wheel.l_b)
	{
		_toping(b, a, data[wheel.l_b - 1], 2);
		print_instr(p(b, a), 2);
	}
	free(data);
}
