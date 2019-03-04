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

NAME = ../push_swap
CC = @ gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -I ./includes/ 

RED=$'\x1b[31m
GREEN=$'\x1b[32m
END=$'\x1b[0m

SRC_UP = ../ft_long_atoi.c\
	  	 ../ft_operations_1.c\

SRC_CHECK =	../src_checker/checker.c\
	  	    ../src_checker/ft_check_list.c\
	  		../src_checker/ft_options.c\

SRC_PUSH = ft_algo_a.c\
		   ft_algo_b.c\
		   ft_push_swap.c\
		   ft_sort_that.c\
		   ft_operations_2.c\
		   ft_double.c\
		   ft_select.c\
		   ft_simple_sort.c\
		   ft_aux.c\
		   ft_algo_aux.c\
		   main_push.c\
		   ft_inst_var.c

OBJ_UP = $(SRC_UP:.c=.o)

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PUSH = $(SRC_PUSH:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_UP) $(OBJ_CHECK) $(OBJ_PUSH)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_UP) $(OBJ_CHECK) $(OBJ_PUSH) -o $(NAME) ../libft/libftprintf.a
	@echo "$(GREEN)PUSH_SWAP COMPILED$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)PUSH_SWAP BINARIES REMOVED$(END)"

clean :
	@rm -f $(OBJ_UP) $(OBJ_CHECK) $(OBJ_PUSH)
	@echo "$(RED)PUSH_SWAP OBJECTS REMOVED$(END)"

re : fclean all
