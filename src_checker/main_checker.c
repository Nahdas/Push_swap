/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:19:23 by alac              #+#    #+#             */
/*   Updated: 2019/03/01 12:19:07 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

void	ft_del_list(t_pile **lst);

int		main(int argc, char **argv)
{
	t_pile	*lst;
	t_pile	*lst_b;
	int		opt;
	char	*line;

	line = "";
	if (argc < 2)
		return (0);
	opt = ft_prealable(argv);
	if (opt < 0)
		return (0);
	lst = NULL;
	if (!(lst = ft_to_list(argv, &lst, opt)) && lst == NULL)
		return (0);
	if (!ft_check_list(lst))
		return (0);
	opt = ft_resolve(&lst, &lst_b, opt, &line);
	if (ft_is_sort(&lst, &lst_b) && opt == 1)
		ft_putstr("OK\n");
	else if (opt == 1)
		ft_putstr("K0\n");
	ft_del_list(&lst);
	ft_del_list(&lst_b);
	while(1);
	return (0);
}
