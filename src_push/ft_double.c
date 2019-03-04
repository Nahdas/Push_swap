/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:05:10 by alac              #+#    #+#             */
/*   Updated: 2019/02/22 18:05:15 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void	ft_ra_rra(t_inst *head, t_inst *prev, t_inst *follow, t_inst **inst)
{
	while (follow != NULL)
	{
		if ((ft_strcmp("ra", head->content) == 0 && ft_strcmp("rra",
		follow->content) == 0) || (ft_strcmp("rra", head->content) == 0
		&& ft_strcmp("ra", follow->content) == 0))
		{
			prev->next = follow->next;
			ft_free(&head);
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

void	ft_rb_rrb(t_inst *head, t_inst *prev, t_inst *follow, t_inst **inst)
{
	while (follow != NULL)
	{
		if ((ft_strcmp("rb", head->content) == 0 && ft_strcmp("rrb",
		follow->content) == 0) || (ft_strcmp("rrb", head->content) == 0
		&& ft_strcmp("rb", follow->content) == 0))
		{
			prev->next = follow->next;
			ft_free(&head);
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

void	ft_ra_rb(t_inst *head, t_inst *prev, t_inst *follow, t_inst **inst)
{
	while (follow != NULL)
	{
		if ((ft_strcmp("ra", head->content) == 0 && ft_strcmp("rb",
		follow->content) == 0) || (ft_strcmp("rb", head->content) == 0
		&& ft_strcmp("ra", follow->content) == 0))
		{
			head->content[1] = 'r';
			head->next = follow->next;
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

void	ft_rra_rrb(t_inst *head, t_inst *prev, t_inst *follow, t_inst **inst)
{
	while (follow != NULL)
	{
		if ((ft_strcmp("rra", head->content) == 0 && ft_strcmp("rrb",
		follow->content) == 0) || (ft_strcmp("rrb", head->content) == 0
		&& ft_strcmp("rra", follow->content) == 0))
		{
			head->content[2] = 'r';
			head->next = follow->next;
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

void	ft_double(t_inst **inst)
{
	t_inst	*head;
	t_inst	*prev;
	t_inst	*follow;

	head = *inst;
	prev = NULL;
	follow = head->next;
	ft_pa_pb(head, prev, follow, inst);
	head = *inst;
	prev = NULL;
	follow = head->next;
	ft_ra_rb(head, prev, follow, inst);
	head = *inst;
	prev = NULL;
	follow = head->next;
	ft_rra_rrb(head, prev, follow, inst);
	head = *inst;
	prev = NULL;
	follow = head->next;
	ft_ra_rra(head, prev, follow, inst);
	head = *inst;
	prev = NULL;
	follow = head->next;
	ft_rb_rrb(head, prev, follow, inst);
}
