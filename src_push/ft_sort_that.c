/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:26:18 by alac              #+#    #+#             */
/*   Updated: 2019/02/18 14:26:19 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void        ft_copy_list(t_pile *lst, t_pile **copy, int len)
{
    t_pile *head;
    
    *copy = NULL;
    while (lst!= NULL && len > 0)
    {
        if (*copy == NULL)
        {
            *copy = ft_pile_new(lst->content, 1);
            head = *copy;
        }
        else
        {
            head = ft_pile_new(lst->content, 1);
            ft_pile_add(copy, head);
        }
        lst = lst->next;
        len--;
    }
}

int     ft_get_size(t_pile *lst)
{
    int i;
    t_pile *head;

    head = lst;
    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    lst = head;
    return(i);
}

int     ft_middle(t_pile *lst, int len)
{
    int ind;
    int i;
    t_pile *tmp;

    tmp = lst;
    i = 0;
    ind = len / 2;
    while (i < ind)
    {
        tmp = tmp->next;
        i++;
    }
    return (tmp->content);
}

int     ft_get_median(t_pile *lst, int len)
{
    t_pile *head;
    t_pile *prev;
    t_pile *follow;
    int res;
    t_pile *copy;

    ft_copy_list(lst, &copy, len);
    head = copy;
    prev = NULL;
    follow = copy->next;
    while (follow != NULL)
    {
        if (copy->content > follow->content)
        {
            copy->next = follow->next;
            follow->next = copy;
            if (copy == head)
                head = follow;
            if (prev && prev != NULL)
                prev->next = follow;
            copy = head;
            prev = NULL;
            follow = copy->next;
        }
        else
        { 
            prev = copy;
            copy = copy->next;
            follow = copy->next;
        }
    }
    res = ft_middle(head, len);
    ft_del_list(&copy);
    return (res);
}

int     ft_sort_that(t_pile **lst_a, t_pile **lst_b)
{
    int size;
    t_pile *head;
    int med;

    size = ft_get_size(*lst_a);
    head = *lst_a;
    med = ft_get_median(head, size);
    ft_partition_A(lst_a, lst_b, size, med);
    return (1);
}