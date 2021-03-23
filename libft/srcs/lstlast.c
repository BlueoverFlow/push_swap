/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:51:52 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/24 20:09:00 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*lstlast(t_list *lst)
{
	int i;
	int j;

	if (lst == NULL)
		return (NULL);
	i = lstsize(lst);
	j = 0;
	while (j < i - 1)
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}
