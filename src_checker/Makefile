# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alac <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 16:41:34 by alac              #+#    #+#              #
#    Updated: 2019/02/14 16:41:36 by alac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker
CC = @ gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -I ./includes/ 

RED=$'\x1b[31m
GREEN=$'\x1b[32m
END=$'\x1b[0m

SRC_PUSH = ../src_push/ft_algo_a.c\
           ../src_push/ft_algo_aux.c\
		   ../src_push/ft_algo_b.c\
		   ../src_push/ft_aux.c\
		   ../src_push/ft_double.c\
		   ../src_push/ft_operations_2.c\
		   ../src_push/ft_push_swap.c\
		   ../src_push/ft_select.c\
		   ../src_push/ft_simple_sort.c\
		   ../src_push/ft_sort_that.c\
		   ../src_push/ft_inst_var.c

SRC = ../ft_long_atoi.c\
	  ../ft_operations_1.c

SRC_CHECK =	checker.c\
	  	    ft_check_list.c\
	  		ft_options.c\
	  		ft_resolve.c\
			main_checker.c

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PUSH = $(SRC_PUSH:.c=.o)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_CHECK) $(OBJ_PUSH) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(OBJ_CHECK) $(OBJ_PUSH) -o $(NAME) ../libft/libftprintf.a
	@echo "$(GREEN)CHECKER COMPILED$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)CHECKER BINARIES REMOVED$(END)"

clean :
	@rm -f $(OBJ) $(OBJ_CHECK) $(OBJ_PUSH)
	@echo "$(RED)CHECKER OBJECTS REMOVED$(END)"

re : fclean all
