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

#include "includes/checker.h"

int         ft_swap(t_pile **lst, char *line, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("sa", line)== 0)
        res += swap(lst);
    if (ft_strcmp("sb", line) == 0)
        res += swap(lst_b);
    if (ft_strcmp("ss", line) == 0)
    {
        swap(lst);
        swap(lst_b);
        return (1);
    }
    return (res);
}

int         ft_push(t_pile **lst, char *line, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("pa", line) == 0)
        res += push(lst, lst_b);
    if (ft_strcmp("pb", line) == 0)
        res += push(lst_b, lst);
    return(res);
}

int         ft_rotate(t_pile **lst, char *line, t_pile **lst_b)
{
    int res;

    res = 0;
    if (ft_strcmp("ra", line) == 0)
        res += rotate(lst);
    if (ft_strcmp("rb", line) == 0)
        res += rotate(lst_b);
    if (ft_strcmp("rr", line) == 0)
    {
        rotate(lst);
        rotate(lst_b);
        return (1);
    }
    if (ft_strcmp("rra", line) == 0)
        res += rev_rotate(lst);
    if (ft_strcmp("rrb", line) == 0)
        res += rev_rotate(lst_b);
    if (ft_strcmp("rrr", line) == 0)
    {
        rev_rotate(lst);
        rev_rotate(lst_b);
        return (1);
    }
    return (res);
}

void        ft_visu(t_pile *lst, t_pile *lst_b, int opt)
{
    
    if (opt == 0)
        return ;
    system("clear");
    ft_printf("\nPILE A :\n____________\n");
    while (lst)
    {
        ft_printf("%d\n", lst->content);
        lst = lst->next;
    }
    ft_printf("\nPILE B :\n_____________\n");
    while (lst_b)
    {
        ft_printf("%d\n", lst_b->content);
        lst_b = lst_b->next;
    }
    usleep(100000);
}

int          ft_resolve(t_pile **lst, t_pile **lst_b, int opt, char **line)
{
    int res;

    res = 0;
    while (get_next_line(0, line))
	{
        res += ft_swap(lst, *line, lst_b);
        res += ft_push(lst, *line, lst_b);
        res += ft_rotate(lst, *line, lst_b);
        if (res != 1)
        {
            ft_putstr("Error\n");
            return(0);
        }
        if (opt == 2)
            ft_visu(*lst, *lst_b, opt);
        res = 0;
    }
    return (1);
}
