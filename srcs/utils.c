/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:53:15 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 08:53:15 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_num(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (str[0] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			out(-1);
		i++;
	}
	if (i == 1 && str[0] == '-')
		out(-1);
}

void	out(int i)
{
	if (i == -1)
		ft_putstr_fd("Error!\n", 1);
	else if (i == 0)
		ft_putstr_fd("KO\n", 1);
	else if (i == 1)
		ft_putstr_fd("OK\n", 1);
	exit(0);
}

void	get_args(t_checker *checker, t_stack **a)
{
	int			i;
	long int	n;

	if (checker->argc == 1)
		exit(0);
	i = 1;
	if (!ft_strcmp(checker->argv[i], "-v"))
		checker->printii = 1;
	else if (!ft_strcmp(checker->argv[i], "-c"))
		checker->printii = 2;
	else
		i = 0;
	while (++i < checker->argc)
	{
		is_num(checker->argv[i]);
		n = ft_atoi(checker->argv[i]);
		if (n == 2147483649)
			out(-1);
		push(a, n);
		a = &((*a)->next);
	}
}

t_stack	*lstlast2(t_stack *lst)
{
	int	i;
	int	j;

	if (lst == NULL)
		return (NULL);
	i = lstsize2(lst);
	j = 0;
	while (j < i - 1)
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}
