# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:57:37 by ael-mezz          #+#    #+#              #
#    Updated: 2021/03/20 22:40:51 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	utils.c			\
		utils_2.c		\
		wheel.c			\
		exec_instr.c	\
		quick_sort.c

LIBFT = libft/libft.a

FLAGS = -g #-Wall -Werror -Wextra -fsanitize=address

SRCS_PATH = ./srcs

CC = gcc

RM = rm -f

OBJ = $(SRCS:.c=.o)

OBJ_DIR = mv *.o srcs

HEADER = includes/push_swap.h

SRCS :=	$(addprefix $(SRCS_PATH)/, $(SRCS))

all: $(SRCS) $(HEADER)
	@cd libft && make all
	@$(CC) srcs/checker.c $(SRCS) $(LIBFT) $(FLAGS) -o checker
	@$(CC) srcs/pushswap.c $(SRCS) $(LIBFT) $(FLAGS) -o push_swap

clean:
	@echo "cleaning..."
	@$(RM) push_swap checker
	@cd libft && make clean
	@clear

fclean: clean
	@cd libft && make fclean

test:
	@$(CC) srcs/$(FILE).c $(LIBFT) $(FLAGS) -o $(FILE)
	@echo "...test...\n\n====================="
	@./$(FILE)

compile:
	@clear
	@$(CC) $(SRCS) $(LIBFT) $(FLAGS) -o $(FILE)

ag:
	@$(CC) srcs/checker.c $(SRCS) $(LIBFT) $(FLAGS) -o checker
	@$(CC) srcs/pushswap.c $(SRCS) $(LIBFT) $(FLAGS) -o push_swap
	@clear

re: fclean all
