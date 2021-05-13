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

SRCS = 				srcs/ft_strcmp.c				\
					srcs/ft_free.c					\
					srcs/ft_atoi.c					\
					srcs/ft_bzero.c					\
					srcs/ft_isalnum.c				\
		   			srcs/ft_isalpha.c				\
		   			srcs/ft_isascii.c				\
		   			srcs/ft_isdigit.c				\
		   			srcs/ft_isprint.c				\
		   			srcs/ft_memccpy.c				\
		   			srcs/ft_memchr.c				\
		   			srcs/ft_memcmp.c				\
					srcs/ft_memcpy.c				\
		   			srcs/ft_memmove.c				\
		   			srcs/ft_memset.c				\
					srcs/ft_strchr.c				\
	   				srcs/ft_strlcat.c				\
	   				srcs/ft_strlcpy.c				\
	   				srcs/ft_strlen.c				\
	   				srcs/ft_strncmp.c				\
	   				srcs/ft_strnstr.c				\
	   				srcs/ft_strrchr.c				\
	   				srcs/ft_tolower.c				\
	   				srcs/ft_toupper.c				\
	   				srcs/ft_calloc.c				\
	   				srcs/ft_strdup.c				\
	   				srcs/ft_substr.c				\
	   				srcs/ft_strjoin.c				\
	   				srcs/ft_strtrim.c				\
	   				srcs/ft_split.c					\
	   				srcs/ft_itoa.c					\
	   				srcs/ft_strmapi.c				\
	   				srcs/ft_putchar_fd.c			\
	   				srcs/ft_putstr_fd.c				\
	   				srcs/ft_putendl_fd.c			\
	   				srcs/ft_putnbr_fd.c				\
	   				srcs/ft_strcpy.c				\
			   		srcs/ft_strcat.c				\
					srcs/ft_ptoa.c					\
					srcs/ft_memalloc.c				\
					srcs/get_next_line.c			\
					srcs/get_next_line_utils.c		\
					srcs/other_functions.c


OBJ_DIR = mv *.o srcs

OBJ = $(SRCS:.c=.o)

HEADER = includes/libft.h

BONUS_SRCS =		srcs/ft_lstnew_bonus.c			\
					srcs/ft_lstadd_front_bonus.c	\
					srcs/ft_lstsize_bonus.c			\
					srcs/ft_lstlast_bonus.c			\
					srcs/ft_lstadd_back_bonus.c		\
					srcs/ft_lstdelone_bonus.c		\
					srcs/ft_lstclear_bonus.c		\
					srcs/ft_lstiter_bonus.c			\
					srcs/ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@echo "\"libft.a\" in process..."
	@$(CC) $(FLAGS) $(SRCS)
	@$(OBJ_DIR)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(BONUS_SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(BONUS_SRCS)
	@$(OBJ_DIR)
	@ar -rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) srcs/*.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
