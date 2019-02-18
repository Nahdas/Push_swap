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

#include "ft_push_swap.h"

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

int     ft_middle(t_pile *lst)
{
    int ind;
    int i;
    t_pile *tmp;

    tmp = lst;
    i = 0;
    ind = ft_get_size(lst) / 2;
    while (i < ind)
    {
        tmp = tmp->next;
        i++;
    }
    return (tmp->content);
}

int     ft_get_median(t_pile *lst)
{
    t_pile *head;
    t_pile *prev;
    t_pile *follow;

    head = lst;
    prev = NULL;
    follow = lst->next;
    while (follow != NULL)
    {
        if (lst->content > follow->content)
        {
            lst->next = follow->next;
            follow->next = lst;
            if (lst == head)
                head = follow;
            if (prev && prev != NULL)
                prev->next = follow;
            lst = head;
            prev = NULL;
            follow = lst->next;
        }
        else
        { 
            prev = lst;
            lst = lst->next;
            follow = lst->next;
        }
    }
    ft_printf("\nsorted \n");
    ft_print_list(head);
    return (ft_middle(head));
}

void        ft_copy_list(t_pile *lst, t_pile **copy)
{
    t_pile *head;
    
    *copy = NULL;
    while (lst!= NULL)
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
    }
}

int     ft_sort_that(t_pile **lst_a, t_pile **lst_b)
{
    int size;
    t_pile *head;
    t_pile *copy;
    int i;
    int med;


    size = ft_get_size(*lst_a);

    head = *lst_a;
    ft_copy_list(head, &copy);
    med = ft_get_median(copy);
    ft_printf("med :%d\n", med);
    while (head->content != med)
    {
        head = head->next;
    }
    while (head->next != NULL)
        rotate(lst_a);
    i = 1;
    head = *lst_a;
    while (i < size)
    {
        if (head->content < med)
            push(lst_b, &head);
        else
            rotate(&head);
        i++;
    }
    ft_printf("\nList_a\n");
    ft_print_list(*lst_a);
    ft_printf("\nList_b\n");
    ft_print_list(*lst_b);
    return (1);
}