/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:23:22 by alac              #+#    #+#             */
/*   Updated: 2019/03/04 13:23:25 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void		ft_del_all(t_pile **lst, t_pile **lst_b, t_inst **inst)
{
	ft_del_list(lst);
	ft_del_list(lst_b);
	ft_del_inst(inst);
}

int			ft_get_inst_size(t_inst *lst)
{
	int		i;
	t_inst	*head;

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

int			main(int argc, char **argv)
{
	t_pile	*lst;
	t_pile	*lst_b;
	t_inst	*inst;
	int		opt;

	if (argc < 2 || ((opt = ft_prealable(argv)) < 0))
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
	if (inst)
	{
		ft_double(&inst);
		ft_print_inst(inst);
	}
	ft_del_all(&lst, &lst_b, &inst);
	return (1);
}
