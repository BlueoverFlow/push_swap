/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:53:26 by ael-mezz          #+#    #+#             */
/*   Updated: 2019/10/25 15:49:25 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;

	if (!(nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1)
			+ ft_strlen(s2) + 1))))
		return (NULL);
	nstr = ft_strcpy(nstr, s1);
	return (ft_strcat(nstr, s2));
}
