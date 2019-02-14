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

NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./src_checker/

SRC = ft_long_atoi.c\
	  ft_operations_1.c\

SRC_CHECK =	src_checker/checker.c\
	  		src_checker/ft_check_list.c\
	  		src_checker/ft_options.c\
	  		src_checker/ft_resolve.c 

OBJ = $(SRC:.c=.o)

OBJ_CHECK = checker.o\
	  		ft_check_list.o\
	  		ft_options.o\
	  		ft_resolve.o 

all : $(NAME)

$(NAME) :
	make -C ./libft
	$(CC) $(CFLAGS) -c $(INCLUDES) $(SRC) $(SRC_CHECK)
	$(CC) $(OBJ) $(OBJ_CHECK) -o $(NAME) ./libft/libftprintf.a 
fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_CHECK)

re : fclean all
