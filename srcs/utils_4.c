/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:52:54 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/12 17:12:47 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_preaxe(t_stack *stack, int axe)
{
	size_t	l;
	int		i;
	int		n;
	int		*data;

	i = -1;
	if (!stack)
		return (0);
	push(&stack, axe);
	l = quicksort(stack, &data);
	free (stack);
	while (++i < l && data[i] != axe)
		;
	if (i == 0)
	{
		n = data[l - 1];
		free(data);
		return (n);
	}
	n = data[i - 1];
	free (data);
	return (n);
}

static	int	_top(t_stack **stack, int data)
{
	int		i;
	int		l;
	int		ninstr;
	t_stack	*tmp;

	ninstr = 0;
	if (!stack || !*stack)
		return (0);
	l = lstsize2(*stack);
	i = lst_order(*stack, data);
	tmp = lstcpy(*stack);
	while (tmp->data != data)
	{
		if (i <= l / 2)
			r(&tmp);
		else
			rr(&tmp);
		ninstr++;
	}
	free_list(&tmp);
	return (ninstr);
}

static int	distance(t_stack *a, t_stack *b, t_wheel wheel, int *similarity)
{
	int	d;

	*similarity = 0;
	if ((lst_order(a, wheel.tmp->data) <= wheel.l_a / 2
			&& lst_order(b, wheel.preaxe) <= wheel.l_b / 2)
		|| (lst_order(a, wheel.tmp->data) > wheel.l_a / 2
			&& lst_order(b, wheel.preaxe) > wheel.l_b / 2))
	{
		if (wheel.top_a > wheel.top_b)
		{
			d = wheel.top_a;
			*similarity = wheel.top_b;
		}
		else
		{
			d = wheel.top_b;
			*similarity = wheel.top_a;
		}
	}
	else
		d = wheel.top_a + wheel.top_b;
	return (d);
}

int	s_scan(t_stack *a, t_stack *b, t_wheel wheel, int *similar)
{
	int		i;
	int		index[MAX_INP];
	int		similarity[MAX_INP];

	wheel.l_a = lstsize2(a);
	wheel.l_b = lstsize2(b);
	wheel.tmp = a;
	*similar = 0;
	i = -1;
	while (++i < wheel.l_a)
	{
		wheel.preaxe = find_preaxe(b, wheel.tmp->data);
		wheel.top_a = _top(&a, wheel.tmp->data);
		wheel.top_b = _top(&b, wheel.preaxe);
		index[i] = distance(a, b, wheel, &similarity[i]);
		wheel.tmp = wheel.tmp->next;
	}
	i = 0;
	wheel.smaller = index[i];
	wheel.top = 0;
	norm_3(&wheel, a, index);
	*similar = similarity[wheel.top];
	return (lst_elem(a, wheel.top));
}
