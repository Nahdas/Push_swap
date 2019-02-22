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

#include "includes/checker.h"

t_list	*ft_to_inst(t_list **inst, char *line)
{
	t_list *head;

	if (!(*inst))
	{
		*inst = ft_lstnew(line, ft_strlen(line));
		head = *inst;
	}
	else
	{
		head = ft_lstnew(line, ft_strlen(line));
		ft_lst_add(inst, head);	
	}
	return (*inst);
}

t_pile 	*ft_to_list(char **argv, t_pile **lst, int opt)
{
	int i;
	long long nb;
	t_pile *head;
	i = 1;
	if (opt > 0)
		i++;
	while (argv[i])
	{
		nb = ft_long_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
		{
			write(2,"Error\n", 6);
			return (NULL);
		}
		else
		{
			if (!(*lst))
			{
				*lst = ft_pile_new(nb, 1);
				head = *lst;
			}
			else
			{
				head = ft_pile_new(nb, 1);
				ft_pile_add(lst, head);
			}
		}
		i++;
	}
	return (*lst);
}

int		ft_offset(char **argv, int opt)
{
	if (opt == 0)
		return (1);
	if (opt == 1 || opt == 2)
		return (2);
	if (opt == 3)
	{
		if (ft_strcmp("-vc", argv[1]) == 0 || ft_strcmp("-cv", argv[1]) == 0)
			return (2);
		else
			return (3);
	}
	return(1);
}

int		ft_is_valid(char **argv, int opt)
{
	int i;
	int j;
	int sign;

	j = 0;
	sign = 0;
	i = ft_offset(argv, opt);
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (-1);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] !='+')
				return (-1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				sign++;
			j++;
		}
		if (sign > 1)
			return (-1);
		j = 0;
		sign = 0;
		i++;
	}
	return (opt);
}