/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:26:18 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 10:58:35 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_copy_list(t_pile *lst, t_pile **copy, int len)
{
	t_pile *head;

	*copy = NULL;
	while (lst != NULL && len > 0)
	{
		if (*copy == NULL)
		{
			*copy = ft_pile_new(lst->content, 1);
			head = *copy;
		}
		else
		{
			head = ft_pile_new(lst->content, 1);
			ft_pile_add(copy, head);
		}
		lst = lst->next;
		len--;
	}
}

int			ft_middle(t_pile *lst, int len)
{
	int		ind;
	int		i;
	t_pile	*tmp;

	tmp = lst;
	i = 0;
	ind = len / 2;
	while (i < ind)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->content);
}

int			ft_bubble_sort(t_pile **copy, t_pile **head, t_pile **prev,
t_pile **follow)
{
	while (*follow != NULL)
	{
		if ((*copy)->content > (*follow)->content)
		{
			(*copy)->next = (*follow)->next;
			(*follow)->next = *copy;
			if (*copy == *head)
				*head = *follow;
			if (*prev && *prev != NULL)
				(*prev)->next = *follow;
			*copy = *head;
			*prev = NULL;
			*follow = (*copy)->next;
		}
		else
		{
			*prev = *copy;
			*copy = (*copy)->next;
			*follow = (*copy)->next;
		}
	}
	return (1);
}

int			ft_get_median(t_pile *lst, int len)
{
	t_pile	*head;
	t_pile	*prev;
	t_pile	*follow;
	int		res;
	t_pile	*copy;

	ft_copy_list(lst, &copy, len);
	head = copy;
	prev = NULL;
	follow = copy->next;
	ft_bubble_sort(&copy, &head, &prev, &follow);
	res = ft_middle(head, len);
	ft_del_list(&head);
	return (res);
}

int			ft_sort_that(t_pile **lst_a, t_pile **lst_b, t_inst **inst)
{
	int		size;
	t_pile	*head;
	int		med;

	size = ft_get_size(*lst_a);
	if (ft_that_is_sorted(*lst_a, size))
		return (1);
	if (size <= 5)
		return (ft_simple_sort(lst_a, lst_b, size, inst));
	head = *lst_a;
	med = ft_get_median(head, size);
	ft_partition_a(lst_a, lst_b, size, inst);
	return (0);
}
