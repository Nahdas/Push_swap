/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:56:54 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 10:57:10 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int			ft_swap_operations(char *op, t_pile **lst_a, t_pile **lst_b,
t_inst **inst)
{
	if (ft_strcmp("sa", op) == 0)
	{
		ft_to_inst(inst, "sa");
		swap(lst_a);
	}
	if (ft_strcmp("sb", op) == 0)
	{
		ft_to_inst(inst, "sb");
		swap(lst_b);
	}
	if (ft_strcmp("ss", op) == 0)
	{
		ft_to_inst(inst, "ss");
		swap(lst_b);
		swap(lst_a);
	}
	return (1);
}

int			ft_push_operations(char *op, t_pile **lst_a, t_pile **lst_b,
t_inst **inst)
{
	if (ft_strcmp("pa", op) == 0)
	{
		ft_to_inst(inst, "pa");
		push(lst_a, lst_b);
	}
	if (ft_strcmp("pb", op) == 0)
	{
		ft_to_inst(inst, "pb");
		push(lst_b, lst_a);
	}
	return (1);
}

int			ft_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b,
t_inst **inst)
{
	if (ft_strcmp("ra", op) == 0)
	{
		ft_to_inst(inst, "ra");
		rotate(lst_a);
	}
	if (ft_strcmp("rb", op) == 0)
	{
		ft_to_inst(inst, "rb");
		rotate(lst_b);
	}
	if (ft_strcmp("rr", op) == 0)
	{
		ft_to_inst(inst, "rr");
		rotate(lst_a);
		rotate(lst_b);
	}
	return (1);
}

int			ft_rev_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b,
t_inst **inst)
{
	if (ft_strcmp(op, "rra") == 0)
	{
		ft_to_inst(inst, "rra");
		rev_rotate(lst_a);
	}
	if (ft_strcmp(op, "rrb") == 0)
	{
		ft_to_inst(inst, "rrb");
		rev_rotate(lst_b);
	}
	if (ft_strcmp(op, "rrr") == 0)
	{
		ft_to_inst(inst, "rrr");
		rev_rotate(lst_b);
		rev_rotate(lst_a);
	}
	return (1);
}

int			ft_get_size(t_pile *lst)
{
	int		i;
	t_pile	*head;

	head = lst;
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst = head;
	return (i);
}
