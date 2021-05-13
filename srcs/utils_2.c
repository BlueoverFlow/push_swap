/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:16:22 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 08:16:22 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_diplucated(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*root;
	int		i;

	tmp = a;
	root = a;
	while (tmp->next)
	{
		a = root;
		i = -1;
		while (a)
		{
			if (a->data == tmp->data)
			{
				i++;
				if (i)
					out(-1);
			}
			a = a->next;
		}
		tmp = tmp->next;
	}
}

void	push(t_stack **head, int data)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	new->next = *head;
	new->data = data;
	*head = new;
}

int	lstsize2(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	free_list(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->next;
	free(*lst);
	*lst = NULL;
	free_list(&tmp);
}
