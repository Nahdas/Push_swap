/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:11:56 by alac              #+#    #+#             */
/*   Updated: 2019/02/25 14:12:00 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void	ft_pa_pb(t_list *head, t_list *prev, t_list *follow, t_list **inst)
{
	while (follow != NULL)
	{
		if ((ft_strcmp("pa", head->content) == 0 && ft_strcmp("pb",
		follow->content) == 0) || (ft_strcmp("pb", head->content) == 0
		&& ft_strcmp("pa", follow->content) == 0))
		{
			prev->next = follow->next;
			//if (*head)
				ft_free(&head);
			//if (*follow)
				ft_free(&follow);
			head = *inst;
			follow = head->next;
			prev = NULL;
		}
		else
		{
			prev = head;
			head = head->next;
			follow = head->next;
		}
	}
}

int		ft_get_min(t_pile *lst, int len)
{
	t_pile	*head;
	t_pile	*copy;
	int		min;

	ft_copy_list(lst, &copy, len);
	head = copy;
	min = head->content;
	while (head != NULL)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	ft_del_list(&copy);
	return (min);
}

int		ft_get_max(t_pile *lst, int len)
{
	t_pile	*head;
	t_pile	*copy;
	int		max;

	ft_copy_list(lst, &copy, len);
	head = copy;
	max = head->content;
	while (head != NULL)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	ft_del_list(&copy);
	return (max);
}

int		ft_that_is_unsorted(t_pile *lst, int len)
{
	t_pile *tmp;
	t_pile *copy;

	ft_copy_list(lst, &copy, len);
	if (copy->next != NULL)
		tmp = copy->next;
	else
		tmp = NULL;
	while (tmp != NULL)
	{
		if (tmp->content > copy->content)
			return (0);
		copy = tmp;
		tmp = tmp->next;
	}
	ft_del_list(&copy);
	return (1);
}

int		ft_that_is_sorted(t_pile *lst, int len)
{
	t_pile *tmp;
	t_pile *copy;

	ft_copy_list(lst, &copy, len);
	if (copy->next != NULL)
		tmp = copy->next;
	else
		tmp = NULL;
	while (tmp != NULL)
	{
		if (tmp->content < copy->content)
			return (0);
		copy = tmp;
		tmp = tmp->next;
	}
	ft_del_list(&copy);
	return (1);
}
