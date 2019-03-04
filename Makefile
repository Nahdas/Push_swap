# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alac <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 16:41:34 by alac              #+#    #+#              #
#    Updated: 2019/03/04 18:12:44 by alac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = make_all

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@make -C ./src_checker
	@make -C ./src_push

fclean : clean
	@make fclean -C ./libft
	@make fclean -C ./src_checker
	@make fclean -C ./src_push

clean :
	@make clean -C ./libft
	@make clean -C ./src_checker
	@make clean -C ./src_push

re : fclean all
