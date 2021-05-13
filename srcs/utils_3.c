/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:22:35 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 10:32:53 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack, t_stack *extra, int code)
{
	t_stack	*tmp;

	if (extra && code == 0)
		out(0);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->next && (tmp->data > tmp->next->data))
		{
			if (code == 0)
				out(0);
			return (0);
		}
		tmp = tmp->next;
	}
	free (tmp);
	if (code == 0)
		out(1);
	return (1);
}

t_stack	*lstcpy(t_stack *lst)
{
	t_stack	*cpy;

	if (lst == NULL)
		return (NULL);
	cpy = malloc(sizeof(*cpy));
	if (!cpy)
		out(-1);
	cpy->data = lst->data;
	cpy->next = lstcpy(lst->next);
	return (cpy);
}

int	lst_order(t_stack *stack, int data)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->data != data && stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	lst_elem(t_stack *stack, int i)
{
	int	j;

	j = -1;
	while (++j != i)
		stack = stack->next;
	return (stack->data);
}
