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

void    ft_del_list(t_pile **lst)
{
    t_pile *current = *lst;
    t_pile *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}

void    ft_print_list(t_pile *lst)
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

int     ft_assemble(t_pile **lst, t_pile **lst_b)
{
    int i;
    int size;

    i = 0;
    size = ft_get_size(*lst_b);
    while (i < size)
    {
        push(lst, lst_b);
        i++;
    }
    return(0);
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
    ft_quick_sort_A(&lst, &lst_b, ft_get_size(lst), 1);
    ft_printf("\n A AFTER FIRST STOP \n");
    ft_print_list(lst);
    ft_printf("\n B AFTER FIRST STOP \n");
    ft_print_list(lst_b);
    getchar();
    ft_quick_sort_B(&lst, &lst_b, ft_get_size(lst_b), -1);
    ft_printf("\n A AFTER FIRST STOP \n");
    ft_print_list(lst);
    ft_printf("\n B AFTER FIRST STOP \n");
    ft_print_list(lst_b);
    getchar();
    ft_assemble(&lst, &lst_b);
    ft_printf("\na la fin la A \n");
    ft_print_list(lst);
    //ft_printf("\na la fin la B \n");
    //ft_print_list(lst_b);
    return(1);
}