/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:52:45 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:30:03 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*is_str2(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strdup2(char *s1)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}

char	*ft_strndup2(const char *s, size_t n)
{
	unsigned int	i;
	char			*cpy;

	cpy = (char *)malloc(sizeof(*cpy) * (n + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strchr2(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*dst;
	char	*str1;
	char	*str2;
	size_t	len;

	if (!s1)
	{
		s1 = ft_strdup2(s2);
		return (s1);
	}
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (*str1)
		*(dst++) = *(str1++);
	while (*str2)
		*(dst++) = *(str2++);
	*dst = '\0';
	return (dst - len);
}
