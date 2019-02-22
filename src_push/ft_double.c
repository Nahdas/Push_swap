/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:05:10 by alac              #+#    #+#             */
/*   Updated: 2019/02/22 18:05:15 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int     ft_pa_pb(t_list **head, t_list **prev, t_list **follow, t_list **inst)
{
    int     i;

    i = 0;
    while ((*follow) != NULL)
    {
        if ((ft_strcmp("pa", (*head)->content) == 0 && ft_strcmp("pb", (*follow)->content) == 0) 
        || (ft_strcmp("pb", (*head)->content) == 0 && ft_strcmp("pa", (*follow)->content) == 0))
        {
            (*prev)->next = (*follow)->next;
            if (*head)
                free(*head);
            if (*follow)
                free(*follow);
            (*head) = *inst;
            (*follow) = (*head)->next;
            (*prev) = NULL;
            i++;
        }
        else
        {
            (*prev) = (*head);
            (*head) = (*head)->next;
            (*follow) = (*head)->next;
        }
    }
    return(i);
}

int     ft_ra_rra(t_list **head, t_list **prev, t_list **follow, t_list **inst)
{
    int     i;

    i = 0;
    while ((*follow) != NULL)
    {
        if ((ft_strcmp("ra", (*head)->content) == 0 && ft_strcmp("rra", (*follow)->content) == 0) 
        || (ft_strcmp("rra", (*head)->content) == 0 && ft_strcmp("ra", (*follow)->content) == 0))
        {
            (*prev)->next = (*follow)->next;
            if (*head)
                free(*head);
            if (*follow)
                free(*follow);
            (*head) = *inst;
            (*follow) = (*head)->next;
            (*prev) = NULL;
            i++;
        }
        else
        {
            (*prev) = (*head);
            (*head) = (*head)->next;
            (*follow) = (*head)->next;
        }
    }
    return(i);
}

int     ft_rb_rrb(t_list **head, t_list **prev, t_list **follow, t_list **inst)
{
    int     i;

    i = 0;
    while ((*follow) != NULL)
    {
        if ((ft_strcmp("rb", (*head)->content) == 0 && ft_strcmp("rrb", (*follow)->content) == 0) 
        || (ft_strcmp("rrb", (*head)->content) == 0 && ft_strcmp("rb", (*follow)->content) == 0))
        {
            (*prev)->next = (*follow)->next;
            if (*head)
                free(*head);
            if (*follow)
                free(*follow);
            (*head) = *inst;
            (*follow) = (*head)->next;
            (*prev) = NULL;
            i++;
        }
        else
        {
            (*prev) = (*head);
            (*head) = (*head)->next;
            (*follow) = (*head)->next;
        }
    }
    return(i);
}

int     ft_ra_rb(t_list **head, t_list **prev, t_list **follow, t_list **inst)
{
    int     i;

    i = 0;
    while ((*follow) != NULL)
    {
        if ((ft_strcmp("ra", (*head)->content) == 0 && ft_strcmp("rb", (*follow)->content) == 0) 
        || (ft_strcmp("rb", (*head)->content) == 0 && ft_strcmp("ra", (*follow)->content) == 0))
        {
            (*head)->content = "rr";
            (*head)->next = (*follow)->next;
            if (*follow)
                free(*follow);
            (*head) = *inst;
            (*follow) = (*head)->next;
            (*prev) = NULL;
            i++;
        }
        else
        {
            (*prev) = (*head);
            (*head) = (*head)->next;
            (*follow) = (*head)->next;
        }
    }
    return(i);
}

int     ft_rra_rrb(t_list **head, t_list **prev, t_list **follow, t_list **inst)
{
    int     i;

    i = 0;
    while ((*follow) != NULL)
    {
        if ((ft_strcmp("rra", (*head)->content) == 0 && ft_strcmp("rrb", (*follow)->content) == 0) 
        || (ft_strcmp("rrb", (*head)->content) == 0 && ft_strcmp("rra", (*follow)->content) == 0))
        {
            (*head)->content = "rrr";
            (*head)->next = (*follow)->next;
            if (*follow)
                free(*follow);
            (*head) = *inst;
            (*follow) = (*head)->next;
            (*prev) = NULL;
            i++;
        }
        else
        {
            (*prev) = (*head);
            (*head) = (*head)->next;
            (*follow) = (*head)->next;
        }
    }
    return(i);
}

int     ft_double(t_list **inst)
{
    t_list  *head;
    t_list  *prev;
    t_list  *follow;
    int     i;

    head = *inst;
    prev = NULL;
    follow = head->next;
    i = 0;
    i += ft_pa_pb(&head, &prev, &follow, inst);
    head = *inst;
    prev = NULL;
    follow = head->next;
    i += ft_ra_rb(&head, &prev, &follow, inst);
    head = *inst;
    prev = NULL;
    follow = head->next;
    i += ft_rra_rrb(&head, &prev, &follow, inst);
    head = *inst;
    prev = NULL;
    follow = head->next;
    i += ft_ra_rra(&head, &prev, &follow, inst);
        head = *inst;
    prev = NULL;
    follow = head->next;
    i += ft_rb_rrb(&head, &prev, &follow, inst);
    return(i);
}