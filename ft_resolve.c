/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:14 by alac              #+#    #+#             */
/*   Updated: 2019/02/11 15:25:33 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int         ft_swap(t_pile **lst, t_list **inst, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("sa", (*inst)->content) == 0)
        res += swap(lst);
    if (ft_strcmp("sb", (*inst)->content) == 0)
        res += swap(lst_b);
    if (ft_strcmp("ss", (*inst)->content) == 0)
    {
        swap(lst);
        swap(lst_b);
        return (1);
    }
    return (res);
}

int         ft_push(t_pile **lst, t_list **inst, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("pa", (*inst)->content) == 0)
        res += push(lst, lst_b);
    if (ft_strcmp("pb", (*inst)->content) == 0)
        res += push(lst_b, lst);
    return(res);
}

int         ft_rotate(t_pile **lst, t_list **inst, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("ra", (*inst)->content) == 0)
        res += rotate(lst);
    if (ft_strcmp("rb", (*inst)->content) == 0)
        res += rotate(lst_b);
    if (ft_strcmp("rr", (*inst)->content) == 0)
    {
        rotate(lst);
        rotate(lst_b);
        return (1);
    }
    if (ft_strcmp("rra", (*inst)->content) == 0)
        res += rev_rotate(lst);
    if (ft_strcmp("rrb", (*inst)->content) == 0)
        res += rev_rotate(lst_b);
    if (ft_strcmp("rrr", (*inst)->content) == 0)
    {
        rev_rotate(lst);
        rev_rotate(lst_b);
        return (1);
    }
    return (res);
}

void        ft_resolve(t_pile **lst, t_list **inst)
{
    t_pile *lst_b;
    int res;

    lst_b = NULL;
    res = 0;
    while (*inst)
    {
        res += ft_swap(lst, inst, &lst_b);
        res += ft_push(lst, inst, &lst_b);
        res += ft_rotate(lst, inst, &lst_b);
        if (res != 1)
        {
            ft_putstr("Error\n");
            return;
        }
        *inst = (*inst)->next;
        res = 0;
    }
    dprintf(2, "PILE A :\n");
    while (*lst)
    {
        ft_printf("%d\n", (*lst)->content);
        *lst = (*lst)->next;
    }
    dprintf(2, "PILE B :\n");
    while (lst_b != NULL)
    {
        ft_printf("%d\n", lst_b->content);
        lst_b = lst_b->next;
    }
}
