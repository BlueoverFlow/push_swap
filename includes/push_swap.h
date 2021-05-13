/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 08:58:04 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 08:58:04 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define MAX_INP 600

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_checker
{
	int		printii;
	char	*instr;
	int		argc;
	char	**argv;
	int		mark_a[MAX_INP];
	int		mark_b[MAX_INP];
	size_t	l_a;
	size_t	l_b;
}			t_checker;

typedef struct s_wheel
{
	int		top_a;
	int		top_b;
	int		top;
	int		smaller;
	int		preaxe;
	int		similarity;
	size_t	l_a;
	size_t	l_b;
	t_stack	*tmp;
	int		*buffer_a;
	int		*buffer_b;
}			t_wheel;

void	out(int i);
void	push(t_stack **head, int data);
void	get_args(t_checker *checker, t_stack **a);
void	print_list(t_stack *a, t_stack *b);
int		lst_order(t_stack *stack, int data);
int		is_sorted(t_stack *a, t_stack *b, int code);
t_stack	*lstlast2(t_stack *lst);
int		lst_elem(t_stack *stack, int i);
void	is_diplucated(t_stack *a);
void	check_input(char *str);
int		s(t_stack **stack);
int		r(t_stack **stack);
int		both(t_stack **a, t_stack **b, int code);
int		p(t_stack **src, t_stack **dst);
int		rr(t_stack **stack);
void	sort(t_stack **a, t_stack **b, t_checker checker);
int		lstsize2(t_stack *lst);
t_stack	*lstcpy(t_stack *lst);
void	free_list(t_stack **lst);
size_t	quicksort(t_stack *stack, int **data);
int		find_preaxe(t_stack *stack, int axe);
void	norm_1(t_stack **stack, t_stack **extra, int s);
void	norm_3(t_wheel *wheel, t_stack *a, int *index);
void	print_instr(int instr, int pres);
void	print_colors(char *str, t_stack *a, t_stack *b, t_checker checker);
int		s_scan(t_stack *a, t_stack *b, t_wheel wheel, int *similar);
void	_toping(t_stack **stack, t_stack **extra, int data, int s);

#endif