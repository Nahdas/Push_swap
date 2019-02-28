/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:02:02 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 14:02:10 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int		ft_rot_a(t_pile **lst_a, t_pile **lst_b, t_list **inst, int *ras)
{
	ft_rot_operations("ra", lst_a, lst_b, inst);
	(*ras)++;
	return (1);
}

int		ft_med_a(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
	ft_push_operations("pb", lst_a, lst_b, inst);
	ft_rot_operations("rb", lst_a, lst_b, inst);
	return (1);
}
