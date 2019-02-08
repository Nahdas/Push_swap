/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:38:58 by alac              #+#    #+#             */
/*   Updated: 2019/02/08 13:15:35 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	ft_is_valid(char **argv, t_list **lst, int opt)
{
	int i;
	long long nb;
	t_list *head;

	i = opt + 1;
	while (argv[i])
	{
		nb = ft_long_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		else
		{
			if (!(*lst))
			{
				*lst = ft_lstnew(NULL, 0);
				(*lst)->content = nb;
				head = *lst;
			}
			else
			{
				head = ft_lstnew(NULL, 0);
				head->content = nb;
				ft_lstadd(lst, head);
			}
		}
	}
	return (*lst);
}

int		main(int argc, char **argv)
{
	static t_list *lst;
	int opt;

	if (argc < 2)
		return (0);
	opt = ft_options(argv);
	if (!ft_is_valid(argv, &lst, opt))
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (lst)
	{
		ft_printf("el :%d\n", lst->content);
		lst = lst->next;
	}
	return (0);
}