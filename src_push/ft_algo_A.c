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

int		ft_partition_a(t_pile **lst_a, t_pile **lst_b, int len, t_inst **inst)
{
	t_pile	*head;
	int		i;
	int		j;
	int		ras;
	int		med;

	med = ft_get_median(*lst_a, len);
	head = *lst_a;
	i = 0;
	j = 0;
	ras = 0;
	while (i < len)
	{
		if (head && head->content < med && j == 0)
			j += ft_push_operations("pb", &head, lst_b, inst);
		if (head && head->content > med && j == 0)
			j += ft_rot_a(&head, lst_b, inst, &ras);
		if (head && head->content == med && j == 0)
			j += ft_med_a(&head, lst_b, inst);
		i++;
		j = 0;
	}
	ft_rev_rot_operations("rrb", &head, lst_b, inst);
	*lst_a = head;
	return (ras);
}

int		ft_two_sorted(t_pile **lst, int order)
{
	t_pile *next;

	next = NULL;
	if ((*lst)->next && (*lst)->next != NULL)
		next = (*lst)->next;
	if (next != NULL && next->content < (*lst)->content && order == 1)
		swap(lst);
	else if (next != NULL && next->content > (*lst)->content && order == -1)
		swap(lst);
	return (1);
}

void	ft_qs_putback_a(t_pile **lst_a, t_pile **lst_b, int ras, t_inst **inst)
{
	int quick;

	quick = 0;
	while (ras > 0)
	{
		if (ras == ft_get_size(*lst_a))
			break ;
		else if (ras > ft_get_size(*lst_a))
			ras = ras - ft_get_size(*lst_a);
		if (ras > ft_get_size(*lst_a) / 2 || quick == 1)
		{
			if (quick == 0)
				ras = ft_get_size(*lst_a) - ras;
			ras = ft_get_size(*lst_a) - ras;
			ft_rot_operations("ra", lst_a, lst_b, inst);
		}
		else
			ft_rev_rot_operations("rra", lst_a, lst_b, inst);
		ras--;
	}
}

int		ft_quick_sort_a(t_pile **lst_a, t_pile **lst_b, int len, t_inst **inst)
{
	int tmp;
	int ras;
	int pbs;
	int quick;

	quick = 0;
	if (len < 2)
		return (1);
	if (ft_that_is_sorted(*lst_a, len))
		return (1);
	ras = ft_partition_a(lst_a, lst_b, len, inst);
	pbs = len - ras;
	tmp = ras;
	ft_qs_putback_a(lst_a, lst_b, ras, inst);
	ras = tmp;
	ft_quick_sort_a(lst_a, lst_b, ras, inst);
	ft_quick_sort_b(lst_a, lst_b, pbs, inst);
	while (pbs > 0)
	{
		ft_push_operations("pa", lst_a, lst_b, inst);
		pbs--;
	}
	return (0);
}
