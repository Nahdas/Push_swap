/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:18:35 by alac              #+#    #+#             */
/*   Updated: 2019/02/11 16:18:38 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    swap(t_pile **lst)
{
    int a;
    int b;
    t_pile *tmp;
    if (!(*lst) || (*lst) == NULL)
        return (0);
    if ((*lst)->next != NULL)
    {

        a = (*lst)->content;
        tmp = *lst;
        *lst = (*lst)->next;
        b = (*lst)->content;
        tmp->content = b;
        (*lst)->content = a;
        (*lst) = tmp;
        return (1);
    }
    else
        return (0);
}

int     push(t_pile **lst, t_pile **lst_b)
{
    int a;
    t_pile *head;

    a = 0;
    if (*lst_b)
    {
        head = (*lst_b);
        head->next = *lst;
        *lst = head;
        ft_del_first(lst_b);
        return (1);
    }
    return(0);
}