/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:33:14 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/12 17:10:34 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init(t_stack *a, t_stack *b, t_checker *checker)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	checker->l_a = lstsize2(a);
	checker->l_b = lstsize2(b);
	while (++i < checker->l_a)
		checker->mark_a[i] = 0;
	while (--j < checker->l_b)
		checker->mark_b[j] = 0;
}

static void	norm_4(char *str, t_stack *a, t_stack *b, t_checker *checker)
{
	if (!ft_strcmp(str, "ra"))
		checker->mark_a[checker->l_a - 1] = 1;
	else if (!ft_strcmp(str, "rb"))
		checker->mark_b[checker->l_b - 1] = 1;
	else if (!ft_strcmp(str, "rr"))
	{
		checker->mark_a[checker->l_a - 1] = 1;
		checker->mark_b[checker->l_b - 1] = 1;
	}
	else if (!ft_strcmp(str, "rra"))
		checker->mark_a[0] = 1;
	else if (!ft_strcmp(str, "rrb"))
		checker->mark_b[0] = 1;
	else if (!ft_strcmp(str, "rrr"))
	{
		checker->mark_a[0] = 1;
		checker->mark_b[0] = 1;
	}
}

static void	last_oper(char *str, t_stack *a, t_stack *b, t_checker *checker)
{
	if (!ft_strcmp(str, "sa"))
	{
		checker->mark_a[0] = 1;
		checker->mark_a[1] = 1;
	}	
	else if (!ft_strcmp(str, "sb"))
	{
		checker->mark_b[0] = 1;
		checker->mark_b[1] = 1;
	}
	else if (!ft_strcmp(str, "ss"))
	{
		checker->mark_a[0] = 1;
		checker->mark_a[1] = 1;
		checker->mark_b[0] = 1;
		checker->mark_b[1] = 1;
	}
	else if (!ft_strcmp(str, "pa"))
		checker->mark_a[0] = 1;
	else if (!ft_strcmp(str, "pb"))
		checker->mark_b[0] = 1;
	else
		norm_4(str, a, b, checker);
	free(str);
}

void	print_list(t_stack *a, t_stack *b)
{
	printf("\t*\n\t*\n\t*\n");
	printf("***************************\n");
	printf("stack a:\tstack b:\n");
	while (a || b)
	{
		if (a)
		{
			printf("%10i\t", a->data);
			a = a->next;
		}
		else if (!a)
			printf("%10c\t", ' ');
		if (b)
		{
			printf("%10i,\n", b->data);
			b = b->next;
		}
		else if (!b)
			printf("%10c,\n", ' ');
	}
	printf("***************************\n");
}

void	print_colors(char *str, t_stack *a, t_stack *b, t_checker checker)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init(a, b, &checker);
	last_oper(str, a, b, &checker);
	printf("\t*\n\t*\n\t*\n");
	printf("***************************\n");
	printf("stack a:\tstack b:\n");
	while (a || b)
	{
		if (a)
		{
			if (checker.mark_a[i] == 1)
				printf("\033[0;32m%10i\t\033[0m", a->data);
			else
				printf("%10i\t", a->data);
			a = a->next;
			i++;
		}
		else if (!a)
			printf("%10c\t", ' ');
		if (b)
		{
			if (checker.mark_b[j] == 1)
				printf("\033[0;32m%10i,\033[0m\n", b->data);
			else
				printf("%10i,\n", b->data);
			b = b->next;
			j++;
		}
		else if (!b)
			printf("%10c,\n", ' ');
	}
	printf("***************************\n");
}
