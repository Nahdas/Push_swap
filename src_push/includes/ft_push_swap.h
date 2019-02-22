/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:12:05 by alac              #+#    #+#             */
/*   Updated: 2019/02/18 13:12:07 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../../src_checker/includes/checker.h"

int     ft_sort_that(t_pile **lst_a, t_pile **lst_b);

int     ft_get_size(t_pile *lst);

void    ft_print_list(t_pile *lst);

int     ft_quick_sort_a(t_pile **lst_a, t_pile **lst_b, int len);

void    ft_del_list(t_pile **lst);

int     ft_get_median(t_pile *lst, int len);

int     ft_quick_sort_B(t_pile **lst_a, t_pile **lst_b, int len, int how);

int     ft_quick_sort_A(t_pile **lst_a, t_pile **lst_b, int len, int how);

int     ft_two_sorted(t_pile **lst, int order);

int     ft_swap_operations(char *op, t_pile **lst_a, t_pile **lst_b);

int     ft_push_operations(char *op, t_pile **lst_a, t_pile **lst_b);

int     ft_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b);

int     ft_rev_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b);

int     ft_partition_A(t_pile **lst_a, t_pile **lst_b, int len, int med);

#endif