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
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -I ./includes/ 

SRC_UP = ../ft_long_atoi.c\
	  	 ../ft_operations_1.c\

SRC_CHECK =	../src_checker/checker.c\
	  	    ../src_checker/ft_check_list.c\
	  		../src_checker/ft_options.c\

SRC_PUSH = ft_algo_A.c\
		   ft_algo_B.c\
		   ft_push_swap.c\
		   ft_sort_that.c\
		   ft_operations_2.c\
		   ft_double.c

OBJ_UP = ft_long_atoi.o\
		 ft_operations_1.o

OBJ_CHECK = checker.o\
	  	    ft_check_list.o\
	  		ft_options.o\

OBJ_PUSH = $(SRC_PUSH:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(INCLUDES) $(SRC_UP) $(SRC_CHECK) $(SRC_PUSH)
	$(CC) $(OBJ_UP) $(OBJ_CHECK) $(OBJ_PUSH) -o $(NAME) ../libft/libftprintf.a 

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ_UP) $(OBJ_CHECK) $(OBJ_PUSH)

re : fclean all
