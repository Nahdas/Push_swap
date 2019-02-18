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

#include "src_checker/checker.h"

int     ft_is_sort(t_pile **lst, t_pile **lst_b)
{
    t_pile *tmp;
    if ((*lst_b))
        return (0);
    if ((*lst)->next != NULL)
        tmp = (*lst)->next;
    else
        tmp = (*lst);
    while (tmp->next != NULL)
    {
        if (tmp->content < (*lst)->content)
            return (0);
        (*lst) = tmp;
        tmp = tmp->next;
    }
    return (1);
}

int    swap(t_pile **lst)
{
    int a;
    int b;
    t_pile *tmp;
    if (!(*lst) || (*lst) == NULL)
        return (1);
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
        return (1);
}

int     rev_rotate(t_pile **lst)
{
    t_pile *tmp;
    t_pile *last;

    if (*lst && (*lst)->next != NULL)
    {
        tmp = (*lst);
        while ((tmp->next)->next != NULL)
            tmp = tmp->next;
        last = tmp->next;
        last->next = (*lst);
        tmp->next = NULL;
        (*lst) = last;
        return(1);
    }
    else
        return(1);
} 

int     rotate(t_pile **lst)
{
    t_pile *tmp;

    if (*lst && (*lst)->next != NULL)
    {
        tmp = (*lst);
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = (*lst);
        tmp = (*lst)->next;
        (*lst)->next = NULL;
        (*lst) = tmp;
        return(1);
    }
    else
        return(1);
} 

int     push(t_pile **lst, t_pile **lst_b)
{
    int a;
    t_pile *head;

    a = 0;
    if (*lst_b)
    {
        head = (*lst_b);
        (*lst_b) = head->next;
        head->next = *lst;
        *lst = head;
        return (1);
    }
    return(1);
}