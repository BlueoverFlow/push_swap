/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 08:16:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/05/05 08:16:01 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static void	fill_array(t_stack *stack, int **data, size_t l)
{
	t_stack	*tmp;
	int		i;

	*data = malloc(sizeof(int) * (l + 1));
	if (!*data)
		out(-1);
	tmp = stack;
	i = -1;
	while (tmp)
	{
		(*data)[++i] = tmp->data;
		tmp = tmp->next;
	}
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = i;
	while (++j <= high - 1)
		if (arr[j] < pivot)
			swap(&arr[++i], &arr[j]);
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	ginjitsu(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ginjitsu(arr, low, pi - 1);
		ginjitsu(arr, pi + 1, high);
	}
}

size_t	quicksort(t_stack *stack, int **data)
{
	size_t	l;

	l = lstsize2(stack);
	fill_array(stack, data, l);
	ginjitsu(*data, 0, l - 1);
	return (l);
}
