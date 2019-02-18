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

#include "ft_push_swap.h"

void    ft_print_list(t_pile *lst)
{
    while (lst != NULL)
    {
        ft_printf("%d\n", lst->content);
        lst = lst->next;
    }
}

int     main(int argc, char **argv)
{
    t_pile *lst;
    t_pile *lst_b;
    int opt;

    if (argc < 2)
        return (0);
    opt = ft_prealable(argv);
    if (opt < 0)
        return (0);
    if (!(lst = ft_to_list(argv, &lst, opt)) && lst == NULL)
        return (0);
    if (!ft_check_list(lst))
        return (0);
    ft_printf("\na la base \n");
    ft_print_list(lst);
    ft_sort_that(&lst, &lst_b);
    //ft_print_list(lst);
    return(1);
}