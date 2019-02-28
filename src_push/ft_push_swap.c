/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:11:57 by alac              #+#    #+#             */
/*   Updated: 2019/02/18 13:11:59 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_del_list(t_pile **lst)
{
	t_pile *current;
	t_pile *next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
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

void		ft_print_inst(t_list *inst)
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

int			ft_assemble(t_pile **lst, t_pile **lst_b, t_list **inst)
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

int			main(int argc, char **argv)
{
	t_pile	*lst;
	t_pile	*lst_b;
	t_list	*inst;
	int		opt;

	if (argc < 2)
		return (0);
	opt = ft_prealable(argv);
	if (opt < 0)
		return (0);
	if (!(lst = ft_to_list(argv, &lst, opt)) && lst == NULL)
		return (0);
	if (!ft_check_list(lst))
		return (0);
	if (ft_sort_that(&lst, &lst_b, &inst) == 0)
	{
		ft_quick_sort_a(&lst, &lst_b, ft_get_size(lst), &inst);
		ft_quick_sort_b(&lst, &lst_b, ft_get_size(lst_b), &inst);
		ft_assemble(&lst, &lst_b, &inst);
	}
	if (!inst)
		return (1);
	ft_double(&inst);
	ft_print_inst(inst);
	return (1);
}
