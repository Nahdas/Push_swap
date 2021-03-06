/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:37:30 by alac              #+#    #+#             */
/*   Updated: 2019/02/22 14:05:12 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/ft_printf.h"
# include <stdlib.h>

struct					s_pile
{
	int					content;
	size_t				content_size;
	struct s_pile		*next;
};
typedef struct s_pile	t_pile;

void					ft_del_list(t_pile **lst);

t_pile					*ft_to_list(char **argv, t_pile **lst, int opt);

int						ft_check_list(t_pile *lst);

long long				ft_long_atoi(const char *str);

int						ft_printf(const char *format, ...);

int						ft_options(char **tab);

void					ft_pile_add(t_pile **alst, t_pile *news);

t_pile					*ft_pile_new(const int	content,
						size_t content_size);

int						ft_prealable(char **argv);

int						ft_is_valid(char **argv, int opt, int j, int sign);

int						ft_resolve(t_pile **lst_b, t_pile **lst,
						int opt, char **line);

int						swap(t_pile **lst);

int						push(t_pile **lst, t_pile **lst_b);

void					ft_del_first(t_pile **alst);

int						rotate(t_pile **lst);

int						rev_rotate(t_pile **lst);

int						ft_is_sort(t_pile *lst, t_pile *lst_b);

void					*ft_write_null(void);

#endif
