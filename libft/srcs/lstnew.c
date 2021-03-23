/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:10:33 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/24 20:02:30 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*lstnew(void *content)
{
	t_list *ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ptr->content = (void *)content;
	ptr->next = NULL;
	return (ptr);
}
