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
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -I ./includes/ 

SRC_PUSH = ../src_push/ft_algo_a.c\
           ../src_push/ft_algo_aux.c\
		   ../src_push/ft_algo_b.c\
		   ../src_push/ft_aux.c\
		   ../src_push/ft_double.c\
		   ../src_push/ft_operations_2.c\
		   ../src_push/ft_push_swap.c\
		   ../src_push/ft_select.c\
		   ../src_push/ft_simple_sort.c\
		   ../src_push/ft_sort_that.c	

SRC = ../ft_long_atoi.c\
	  ../ft_operations_1.c

SRC_CHECK =	checker.c\
	  	    ft_check_list.c\
	  		ft_options.c\
	  		ft_resolve.c\
			main_checker.c

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PUSH = ft_algo_a.o\
           ft_algo_aux.o\
		   ft_algo_b.o\
		   ft_aux.o\
		   ft_double.o\
		   ft_operations_2.o\
		   ft_push_swap.o\
		   ft_select.o\
		   ft_simple_sort.o\
		   ft_sort_that.o	

OBJ = 		ft_long_atoi.o\
	  		ft_operations_1.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(INCLUDES) $(SRC) $(SRC_CHECK) $(SRC_PUSH)
	$(CC) $(OBJ) $(OBJ_CHECK) $(OBJ_PUSH) -o $(NAME) ../libft/libftprintf.a 

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_CHECK) $(OBJ_PUSH)

re : fclean all
