/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:50:30 by alac              #+#    #+#             */
/*   Updated: 2019/02/20 09:50:32 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int		ft_rot_b(t_pile **lst_a, t_pile **lst_b, t_inst **inst, int *rbs)
{
	ft_rot_operations("rb", lst_a, lst_b, inst);
	(*rbs)++;
	return (1);
}

int		ft_med_b(t_pile **lst_a, t_pile **lst_b, t_inst **inst)
{
	ft_push_operations("pa", lst_a, lst_b, inst);
	ft_rot_operations("ra", lst_a, lst_b, inst);
	return (1);
}

int		ft_partition_b(t_pile **lst_a, t_pile **lst_b, int len, t_inst **inst)
{
	t_pile	*head;
	int		i;
	int		j;
	int		rbs;
	int		med;

	med = ft_get_median(*lst_b, len);
	head = *lst_b;
	i = 0;
	j = 0;
	rbs = 0;
	while (i < len)
	{
		if (head && head->content > med && j == 0)
			j += ft_push_operations("pa", lst_a, &head, inst);
		if (head && head->content < med && j == 0)
			j += ft_rot_b(lst_a, &head, inst, &rbs);
		if (head && head->content == med && j == 0)
			j += ft_med_b(lst_a, &head, inst);
		i++;
		j = 0;
	}
	ft_rev_rot_operations("rra", lst_a, &head, inst);
	*lst_b = head;
	return (rbs);
}

void	ft_qs_putback_b(t_pile **lst_a, t_pile **lst_b, int rbs, t_inst **inst)
{
	int quick;

	quick = 0;
	while (rbs > 0)
	{
		if (rbs == ft_get_size(*lst_b))
			break ;
		else if (rbs > ft_get_size(*lst_b))
			rbs = rbs - ft_get_size(*lst_b);
		if (rbs > ft_get_size(*lst_b) / 2 || quick == 1)
		{
			if (quick == 0)
				rbs = ft_get_size(*lst_b) - rbs;
			rbs = ft_get_size(*lst_b) - rbs;
			ft_rot_operations("rb", lst_a, lst_b, inst);
		}
		else
			ft_rev_rot_operations("rrb", lst_a, lst_b, inst);
		rbs--;
	}
}

int		ft_quick_sort_b(t_pile **lst_a, t_pile **lst_b, int len, t_inst **inst)
{
	int tmp;
	int rbs;
	int pas;

	if (len < 2)
		return (1);
	if (ft_that_is_unsorted(*lst_b, len))
		return (1);
	rbs = ft_partition_b(lst_a, lst_b, len, inst);
	pas = len - rbs;
	tmp = rbs;
	ft_qs_putback_b(lst_a, lst_b, rbs, inst);
	rbs = tmp;
	ft_quick_sort_b(lst_a, lst_b, rbs, inst);
	ft_quick_sort_a(lst_a, lst_b, pas, inst);
	while (pas > 0)
	{
		ft_push_operations("pb", lst_a, lst_b, inst);
		pas--;
	}
	return (0);
}
