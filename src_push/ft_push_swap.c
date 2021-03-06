/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:11:57 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 17:37:39 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_del_inst(t_inst **lst)
{
	t_inst *tmp;

	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		ft_free(&tmp);
		tmp = NULL;
	}
	lst = NULL;
}

void		ft_del_list(t_pile **lst)
{
	t_pile *tmp;

	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
	lst = NULL;
}

void		ft_print_list(t_pile *lst)
{
	if (lst)
	{
		while (lst != NULL)
		{
			ft_printf("%d\n", lst->content);
			lst = lst->next;
		}
	}
}

void		ft_print_inst(t_inst *inst)
{
	if (inst)
	{
		while (inst != NULL)
		{
			ft_printf("%s\n", inst->content);
			inst = inst->next;
		}
	}
}

int			ft_assemble(t_pile **lst, t_pile **lst_b, t_inst **inst)
{
	int i;
	int size;

	i = 0;
	size = ft_get_size(*lst_b);
	while (i < size)
	{
		ft_push_operations("pa", lst, lst_b, inst);
		i++;
	}
	return (0);
}
