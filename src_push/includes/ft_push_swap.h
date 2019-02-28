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

int		ft_rot_a(t_pile **lst_a, t_pile **lst_b, t_list **inst, int *ras);

int		ft_med_a(t_pile **lst_a, t_pile **lst_b, t_list **inst);

void	ft_insert_and_set(t_pile **lst_a, t_pile **lst_b, t_list **inst);

void	ft_put_back(t_pile **lst_a, t_pile **lst_b, t_list **inst, int ras);

void	ft_rra_sa(t_pile **lst_a, t_pile **lst_b, t_list **inst);

void	ft_sa_rra(t_pile **lst_a, t_pile **lst_b, t_list **inst);

void	ft_pa_pb(t_list **head, t_list **prev, t_list **follow, t_list **inst);

void	ft_double(t_list **inst);

int		ft_get_min(t_pile *lst, int len);

int		ft_get_max(t_pile *lst, int len);

int		ft_sort_that(t_pile **lst_a, t_pile **lst_b, t_list **inst);

int		ft_get_size(t_pile *lst);

void	ft_print_list(t_pile *lst);

void	ft_del_list(t_pile **lst);

void	ft_copy_list(t_pile *lst, t_pile **copy, int len);

int		ft_get_median(t_pile *lst, int len);

int		ft_simple_sort(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst);

int		ft_quick_sort_b(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst);

int		ft_quick_sort_a(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst);

int		ft_two_sorted(t_pile **lst, int order);

int		ft_that_is_sorted(t_pile *lst, int len);

int		ft_that_is_unsorted(t_pile *lst, int len);

int		ft_swap_operations(char *op, t_pile **lst_a, t_pile **lst_b,
		t_list **inst);

int		ft_push_operations(char *op, t_pile **lst_a, t_pile **lst_b,
		t_list **inst);

int		ft_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b,
		t_list **inst);

int		ft_rev_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b,
		t_list **inst);

int		ft_partition_a(t_pile **lst_a, t_pile **lst_b, int len,
		t_list **inst);

#endif
