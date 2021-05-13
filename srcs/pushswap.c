/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:54:54 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/03 10:54:59 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_(t_checker *checker, int argc, char **argv, t_stack **a)
{
	checker->argc = argc;
	checker->argv = argv;
	get_args(checker, a);
	is_diplucated(*a);
}

int	main(int argc, char **argv)
{
	t_checker	checker;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	init_(&checker, argc, argv, &a);
	if (is_sorted(a, b, 1))
		return (0);
	sort(&a, &b, checker);
	free_list(&a);
	return (0);
}
