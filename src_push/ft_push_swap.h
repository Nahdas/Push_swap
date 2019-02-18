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

# include "../src_checker/checker.h"

int     ft_sort_that(t_pile **lst_a, t_pile **lst_b);

int     ft_get_size(t_pile *lst);

void    ft_print_list(t_pile *lst);

#endif