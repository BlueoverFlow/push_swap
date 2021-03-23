/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:04:21 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/24 21:29:16 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	lstclear(&(*lst)->next, del);
	lstdelone(*lst, del);
	*lst = NULL;
}
