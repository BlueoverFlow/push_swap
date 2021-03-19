/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:50:03 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:30:22 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
char	*is_str2(size_t size);
char	*ft_strdup2(char *s1);
char	*ft_strndup2(const char *s, size_t n);
char	*ft_strchr2(const char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
int		get_buffer(char **buffer, char *reader, int fd, int *ret);
char	*get_line(char **buffer);

#endif
