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

SRC = ../ft_long_atoi.c\
	  ../ft_operations_1.c\

SRC_CHECK =	checker.c\
	  	    ft_check_list.c\
	  		ft_options.c\
	  		ft_resolve.c\
			main_checker.c

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ = 		ft_long_atoi.o\
	  		ft_operations_1.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(INCLUDES) $(SRC) $(SRC_CHECK)
	$(CC) $(OBJ) $(OBJ_CHECK) -o $(NAME) ../libft/libftprintf.a 

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_CHECK)

re : fclean all
