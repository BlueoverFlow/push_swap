# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <ael-mezz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:57:37 by ael-mezz          #+#    #+#              #
#    Updated: 2021/02/25 16:51:54 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

CC = gcc

RM = rm -f

SRCS_PATH = ./srcs

SRCS = 	ft_strcmp.c					\
		ft_free.c					\
		ft_atoi.c					\
		ft_bzero.c					\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_isprint.c				\
		ft_memccpy.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_memcpy.c					\
		ft_memmove.c				\
		ft_memset.c					\
		ft_strchr.c					\
	   	ft_strlcat.c				\
	   	ft_strlcpy.c				\
	   	ft_strlen.c					\
	   	ft_strncmp.c				\
	   	ft_strnstr.c				\
	   	ft_strrchr.c				\
	   	ft_tolower.c				\
	   	ft_toupper.c				\
	   	ft_calloc.c					\
	   	ft_strdup.c					\
	   	ft_substr.c					\
	   	ft_strjoin.c				\
	   	ft_strtrim.c				\
	   	ft_split.c					\
	   	ft_itoa.c					\
	   	ft_strmapi.c				\
	   	ft_putchar_fd.c				\
	   	ft_putstr_fd.c				\
	   	ft_putendl_fd.c				\
	   	ft_putnbr_fd.c				\
	   	ft_strcpy.c					\
		ft_strcat.c					\
		ft_ptoa.c					\
		ft_memalloc.c				\
		get_next_line.c				\
		get_next_line_utils.c		\
		other_functions.c			\
		lstnew.c					\
		lstadd_front.c				\
		lstsize.c					\
		lstlast.c					\
		lstadd_back.c				\
		lstdelone.c					\
		lstclear.c					\
		lstiter.c					\
		lstmap.c
		

SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS))


OBJ_DIR = mv *.o srcs

OBJ = $(SRCS:.c=.o)

HEADER = includes/libft.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@echo "\"libft.a\" in process..."
	@$(CC) $(FLAGS) $(SRCS)
	@$(OBJ_DIR)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) srcs/*.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all
