# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmariott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 09:31:53 by lmariott          #+#    #+#              #
#    Updated: 2019/03/01 12:15:26 by alac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @ gcc -Wall -Werror -Wextra


SRC = ft_isalnum.c	ft_isprint.c	ft_memcpy.c	ft_strchr.c	ft_strlcat.c\
  	  ft_strncpy.c	ft_tolower.c\
	  ft_isalpha.c	ft_memccpy.c	ft_memmove.c	ft_strcmp.c\
  	  ft_strlen.c	ft_strnstr.c	ft_toupper.c\
	  ft_atoi.c	ft_isascii.c	ft_memchr.c	ft_memset.c\
  	  ft_strcpy.c	ft_strncat.c	ft_strrchr.c\
	  ft_bzero.c	ft_isdigit.c	ft_memcmp.c	ft_memdel.c\
  	  ft_strcat.c	ft_strdup.c	ft_strncmp.c	ft_strstr.c\
	  ft_strdel.c	ft_memalloc.c	ft_strnew.c	ft_strclr.c\
	  ft_striter.c	ft_striteri.c	ft_strmap.c	ft_strmapi.c\
	  ft_strequ.c	ft_strnequ.c	ft_strsub.c	ft_strjoin.c\
	  ft_strtrim.c	ft_strsplit.c	ft_itoa.c	ft_putchar.c\
	  ft_putstr.c	ft_putendl.c	ft_putnbr.c	ft_putchar_fd.c\
	  ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
	  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c\
	  ft_lstadd.c	ft_lstiter.c	ft_lstmap.c	ft_strclen.c\
	  ft_sqrt.c	get_next_line.c ft_strcdup.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@cp $(OBJ) ../
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(OBJ) $(addprefix ../, $(OBJ))

re : fclean all
