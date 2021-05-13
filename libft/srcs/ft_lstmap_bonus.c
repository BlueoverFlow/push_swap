/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:40:42 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/29 14:06:06 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*lst2;
	t_list		*tmp;

	if (f == NULL || lst == NULL)
		return (NULL);
	lst2 = NULL;
	tmp = lst2;
	while (lst)
	{
		lst2 = ft_lstnew((*f)(lst->content));
		if (!lst2)
		{
			(ft_lstclear(&tmp, del));
			return (NULL);
		}
		ft_lstadd_back(&tmp, lst2);
		lst = lst->next;
		lst2 = lst2->next;
	}
	return (lst2);
}
