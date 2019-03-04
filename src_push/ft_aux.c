/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:39:56 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 12:40:01 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_sa_rra(t_pile **lst_a, t_pile **lst_b, t_inst **inst)
{
	ft_swap_operations("sa", lst_a, lst_b, inst);
	ft_rev_rot_operations("rra", lst_a, lst_b, inst);
}

void		ft_rra_sa(t_pile **lst_a, t_pile **lst_b, t_inst **inst)
{
	ft_rev_rot_operations("rra", lst_a, lst_b, inst);
	ft_swap_operations("sa", lst_a, lst_b, inst);
}

void		ft_put_back(t_pile **lst_a, t_pile **lst_b, t_inst **inst, int ras)
{
	int quick;

	quick = 0;
	while (ras > 0)
	{
		if (ras == ft_get_size(*lst_a))
			break ;
		else if (ras > ft_get_size(*lst_a))
			ras = ras - ft_get_size(*lst_a);
		if (ras > 2 || quick == 1)
		{
			if (quick == 0)
				ras = ft_get_size(*lst_a) - ras;
			quick = 1;
			ft_rot_operations("ra", lst_a, lst_b, inst);
		}
		else
			ft_rev_rot_operations("rra", lst_a, lst_b, inst);
		ras--;
	}
}

void		ft_insert_and_set(t_pile **lst_a, t_pile **lst_b, t_inst **inst)
{
	int ras;

	ras = 0;
	while ((*lst_a)->content < (*lst_b)->content)
	{
		ft_rot_operations("ra", lst_a, lst_b, inst);
		ras++;
	}
	ft_push_operations("pa", lst_a, lst_b, inst);
	ft_put_back(lst_a, lst_b, inst, ras);
}
