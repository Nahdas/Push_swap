/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:55:55 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 11:56:00 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_sort_three(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
	t_pile *first;
	t_pile *sec;
	t_pile *third;

	first = *lst_a;
	sec = first->next;
	third = sec->next;
	if (first->content > sec->content && sec->content < third->content &&
	third->content < first->content)
		ft_rot_operations("ra", lst_a, lst_b, inst);
	if (first->content < sec->content && sec->content > third->content &&
	third->content < first->content)
		ft_rev_rot_operations("rra", lst_a, lst_b, inst);
	if (first->content > sec->content && sec->content > third->content &&
	third->content < first->content)
		ft_sa_rra(lst_a, lst_b, inst);
	if (first->content < sec->content && sec->content > third->content &&
	third->content > first->content)
		ft_rra_sa(lst_a, lst_b, inst);
	if (first->content > sec->content && sec->content < third->content &&
	third->content > first->content)
		ft_swap_operations("sa", lst_a, lst_b, inst);
}

void		ft_sort_four(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
	int ras;
	int min;
	int max;

	ras = 0;
	min = ft_get_min(*lst_a, 4);
	max = ft_get_max(*lst_a, 4);
	while ((*lst_a)->content == min || (*lst_a)->content == max)
		ft_rot_operations("ra", lst_a, lst_b, inst);
	ft_push_operations("pb", lst_a, lst_b, inst);
	ft_sort_three(lst_a, lst_b, inst);
	while ((*lst_a)->content < (*lst_b)->content)
	{
		ft_rot_operations("ra", lst_a, lst_b, inst);
		ras++;
	}
	ft_push_operations("pa", lst_a, lst_b, inst);
	ft_put_back(lst_a, lst_b, inst, ras);
}

void		ft_sort_five(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
	int min;
	int max;

	min = ft_get_min(*lst_a, 5);
	max = ft_get_max(*lst_a, 5);
	while ((*lst_a)->content == min || (*lst_a)->content == max)
		ft_rot_operations("ra", lst_a, lst_b, inst);
	ft_push_operations("pb", lst_a, lst_b, inst);
	while ((*lst_a)->content == min || (*lst_a)->content == max)
		ft_rot_operations("ra", lst_a, lst_b, inst);
	ft_push_operations("pb", lst_a, lst_b, inst);
	ft_sort_three(lst_a, lst_b, inst);
	ft_insert_and_set(lst_a, lst_b, inst);
	ft_insert_and_set(lst_a, lst_b, inst);
}

int			ft_simple_sort(t_pile **lst_a, t_pile **lst_b, int len,
t_list **inst)
{
	t_pile *head;
	t_pile *follow;

	if (ft_that_is_sorted(*lst_a, len))
		return (1);
	follow = NULL;
	head = (*lst_a);
	if (head->next != NULL)
		follow = head->next;
	if (len == 2)
	{
		if (head->content > follow->content)
			ft_swap_operations("sa", &head, lst_b, inst);
	}
	if (len == 3)
		ft_sort_three(lst_a, lst_b, inst);
	if (len == 4)
		ft_sort_four(lst_a, lst_b, inst);
	if (len == 5)
		ft_sort_five(lst_a, lst_b, inst);
	return (1);
}
