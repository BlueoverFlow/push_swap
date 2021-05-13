/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:15:12 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 08:15:12 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_(t_checker *checker, int argc, char **argv, t_stack **a)
{
	checker->argc = argc;
	checker->argv = argv;
	checker->printii = 0;
	get_args(checker, a);
	is_diplucated(*a);
}

static void	exec_instr(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa"))
		s(a);
	else if (!ft_strcmp(str, "sb"))
		s(b);
	else if (!ft_strcmp(str, "ss"))
		both(a, b, 1);
	else if (!ft_strcmp(str, "pa"))
		p(b, a);
	else if (!ft_strcmp(str, "ra"))
		r(a);
	else if (!ft_strcmp(str, "rb"))
		r(b);
	else if (!ft_strcmp(str, "rr"))
		both(a, b, 2);
	else if (!ft_strcmp(str, "pb"))
		p(a, b);
	else if (!ft_strcmp(str, "rra"))
		rr(a);
	else if (!ft_strcmp(str, "rrb"))
		rr(b);
	else if (!ft_strcmp(str, "rrr"))
		both(a, b, 3);
	else
		out(-1);
}

int	main(int argc, char **argv)
{
	t_checker	checker;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	init_(&checker, argc, argv, &a);
	if (checker.printii != 0)
		print_list(a, b);
	while (get_next_line(0, &checker.instr) > 0)
	{
		exec_instr(checker.instr, &a, &b);
		if (checker.printii == 1)
			print_list(a, b);
		else if (checker.printii == 2)
			print_colors(checker.instr, a, b, checker);
		free(checker.instr);
	}
	is_sorted(a, b, 0);
	return (0);
}
