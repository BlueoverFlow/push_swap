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

SRCS = 	$(FILE).c		\
		utils.c			\
		utils_2.c		\
		quick_sort.c	\
		exec_instr.c

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
	@cd libft && make all && make bonus && cd ..
	@$(CC) $(SRCS) $(LIBFT) $(FLAGS) -o push_swap

clean:
	@echo "cleaning..."
	@$(RM) $(FILE)
	@cd srcs && $(RM) *.o
	@cd libft && make clean
	@clear

tclean:
	@$(RM) $(FILE)

test: tclean
	@$(CC) srcs/$(FILE).c $(LIBFT) $(FLAGS) -o $(FILE)
	@echo "...test...\n\n====================="
	@./$(FILE)

compile: tclean
	@clear
	@$(CC) $(SRCS) $(LIBFT) $(FLAGS) -o $(FILE)

ag: compile exec

fclean: clean
	@$(RM) $(LIBFT)
	@cd libft && make fclean

exec:
	@echo "executing...\n\n====================="
	@./$(FILE) 2 3 12 1 10 6 9 7 4 5 8 11
	@echo =====================

re: fclean all exec
