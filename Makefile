# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:57:37 by ael-mezz          #+#    #+#              #
#    Updated: 2021/02/25 17:57:06 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a

FLAGS = -g

SRCS = 	checker.c		\
		push_swap.c		\
		utils.c			\
		utils_2.c

SRCS_PATH = ./srcs

SRCS :=	$(addprefix $(SRCS_PATH)/, $(SRCS))

CC = gcc

RM = rm -f

LIBFT_OBJ_PTH = libft/srcs/*.o

OBJ = $(SRCS:.c=.o)

OBJ_DIR = mv *.o srcs

HEADER = includes/push_swap.h

all: $(SRCS) $(HEADER)
	@cd libft && make all && make bonus
	@cd ..
	@$(CC) $(SRCS) $(NAME) $(FLAGS) -o push_swap

clean:
	@echo "cleaning..."
	@cd srcs && $(RM) *.o
	@cd libft && make clean
	@$(RM) push_swap
	@clear

test: tclean
	@$(CC) srcs/$(FILE).c $(NAME) $(FLAGS) -o $(FILE)
	@echo "...test...\n\n====================="
	@./$(FILE)

compile: tclean
	@clear
	@$(CC) $(SRCS) $(NAME) $(FLAGS) -o $(FILE)

ag: compile exec

tclean:
	@$(RM) $(FILE)

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean

exec:
	@echo "executing...\n\n====================="
	@./$(FILE) 5 6 4 854 12
	@echo =====================

re: fclean all exec
