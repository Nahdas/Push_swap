/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:23:32 by alac              #+#    #+#             */
/*   Updated: 2019/03/04 13:23:34 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void			ft_lst_add(t_inst **alst, t_inst *news)
{
	t_inst *current;

	if (alst && news)
	{
		current = *alst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = news;
	}
}

t_inst			*ft_inst_new(char *content)
{
	t_inst	*tmp;

	if (!(tmp = (t_inst *)malloc(sizeof(t_pile))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		tmp->content = ft_strdup(content);
		tmp->next = NULL;
		return (tmp);
	}
}

t_inst			*ft_to_inst(t_inst **inst, char *line)
{
	t_inst *head;

	if (!(*inst))
	{
		*inst = ft_inst_new(line);
		head = *inst;
	}
	else
	{
		head = ft_inst_new(line);
		ft_lst_add(inst, head);
	}
	return (*inst);
}
