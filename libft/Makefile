# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmariott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 11:49:47 by lmariott          #+#    #+#              #
#    Updated: 2019/02/08 11:30:35 by alac             ###   ########.fr        #
#    Updated: 2018/12/11 16:01:32 by alac             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft/
SRC = ft_printf.c\
	  ft_list.c\
	  ft_capture_the_flag.c\
	  ft_put_base.c\
	  ft_uint_x_min.c\
	  ft_uint_x_maj.c\
	  ft_uint_u.c\
	  ft_uint_o.c\
	  ft_p_address.c\
	  ft_int.c\
	  ft_char.c\
	  ft_char_star.c\
	  ft_nbrlen_base.c\
	  ft_help.c\
	  ft_any.c\
	  ft_double_f.c\
	  ft_flag_convert_int.c

OBJLIBFT = ft_isalnum.o	ft_isprint.o	ft_memcpy.o	ft_strchr.o	ft_strlcat.o\
	  ft_strncpy.o	ft_tolower.o\
	  ft_isalpha.o	ft_memccpy.o	ft_memmove.o	ft_strcmp.o\
	  ft_strlen.o	ft_strnstr.o	ft_toupper.o\
	  ft_atoi.o	ft_isascii.o	ft_memchr.o	ft_memset.o\
	  ft_strcpy.o	ft_strncat.o	ft_strrchr.o\
	  ft_bzero.o	ft_isdigit.o	ft_memcmp.o	ft_memdel.o\
	  ft_strcat.o	ft_strdup.o	ft_strncmp.o	ft_strstr.o\
	  ft_strdel.o	ft_memalloc.o	ft_strnew.o	ft_strclr.o\
	  ft_striter.o	ft_striteri.o	ft_strmap.o	ft_strmapi.o\
	  ft_strequ.o	ft_strnequ.o	ft_strsub.o	ft_strjoin.o\
	  ft_strtrim.o	ft_strsplit.o	ft_itoa.o	ft_putchar.o\
	  ft_putstr.o	ft_putendl.o	ft_putnbr.o	ft_putchar_fd.o\
	  ft_putstr_fd.o	ft_putendl_fd.o	ft_putnbr_fd.o\
	  ft_lstnew.o	ft_lstdelone.o	ft_lstdel.o\
	  ft_lstadd.o	ft_lstiter.o	ft_lstmap.o	ft_strclen.o\
	  ft_sqrt.o ft_strcdup.o get_next_line.o

OBJ = $(SRC:.c=.o)

all : lib $(NAME)

lib :
	make -C ./libft

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJLIBFT)
	ranlib $(NAME)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJ)

re : fclean all
