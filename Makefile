# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:57:37 by ael-mezz          #+#    #+#              #
#    Updated: 2021/05/12 17:06:21 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	utils.c			\
		utils_2.c		\
		utils_3.c		\
		utils_4.c		\
		wheel.c			\
		utils_5.c		\
		exec_instr.c	\
		quick_sort.c	\
		bonus.c

LIBFT =	libft/libft.a

FLAGS =	-g #-fsanitize=address #-Wall -Werror -Wextra

SRCS_PATH =	./srcs

CC = gcc

RM = rm -f

OBJ = $(SRCS:.c=.o)

OBJ_DIR = mv *.o srcs

HEADER = includes/push_swap.h

SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS))

ops: $(SRCS) $(HEADER)
	@cd libft && make all && make bonus
	@$(CC) srcs/checker.c $(SRCS) $(LIBFT) $(FLAGS) -o checker
	@$(CC) srcs/pushswap.c $(SRCS) $(LIBFT) $(FLAGS) -o push_swap

clean:
	@echo "cleaning..."

fclean:	clean
	@$(RM) *checker *push_swap
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

re: fclean ops