/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:50:30 by alac              #+#    #+#             */
/*   Updated: 2019/02/20 09:50:32 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int     ft_partition_A(t_pile **lst_a, t_pile **lst_b, int len, int med)
{
    t_pile *head;
    int i;
    int j;
    int ras;

    head = *lst_a;
    i = 0;
    j = 0;
    ras = 0;
    while (i < len)
    {
        dprintf(2, "a\n");
        if (head && head->content < med && j == 0)
        {
            dprintf(2, "a'\n");
            push(lst_b, &head);
            j++;
        }
        dprintf(2, "b\n");
        if (head && head->content > med && j == 0)
        {
            dprintf(2, "b'\n");
            rotate(&head);
            ras++;
            j++;
        }
        dprintf(2, "c\n");
        if (head && head->content == med && j == 0)
        {
            dprintf(2, "c'\n");
            push(lst_b, &head);
            rotate(lst_b);
            j++;
        }
        dprintf(2, "d\n");
        i++;
        j = 0;
        ft_printf("ras: %d, med :%d, len: %d i :%d\n", ras, med, len, i);
        ft_printf("\nList_a dans qsA-partition\n");
        ft_print_list(head);
        ft_printf("\nList_b dans qsA-partition\n");
        ft_print_list(*lst_b);
        getchar();
    }
    dprintf(2 ,"e\n");
    rev_rotate(lst_b);
    *lst_a = head;
    return(ras);
}

int     ft_two_sorted(t_pile **lst, int order)
{
    t_pile *next;

    next = NULL;
    if ((*lst)->next && (*lst)->next != NULL)
        next = (*lst)->next;
    if (next != NULL && next->content < (*lst)->content && order == 1)
        swap(lst);
    else if (next != NULL && next->content > (*lst)->content && order == -1)
        swap(lst);
    ft_printf("SORTED\n");
    return(1);
    
}

int     ft_quick_sort_A(t_pile **lst_a, t_pile **lst_b, int len, int how)
{
    ft_printf("\nList_a dans qsA\n");
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsA\n");
    ft_print_list(*lst_b);
    getchar();

    int med;
    int ras;
    int pbs;

    if (len < 2)
        return(1);
    dprintf(2, "len is :%d\n", len);
    med = ft_get_median(*lst_a, len);
    ras = ft_partition_A(lst_a, lst_b, len, med);
    dprintf(2, "ras is :%d\n", ras);
    pbs = len - ras;
    dprintf(2, "pbs is :%d\n", pbs);
    ft_quick_sort_A(lst_a, lst_b, ras, how);
    ft_quick_sort_B(lst_a, lst_b, pbs, how);
    while (ras > 0)
    {
        rev_rotate(lst_a);
        ras--;
        ft_printf("\nList_a dans qsA-ras loop\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsA-ras loop\n");
        ft_print_list(*lst_b);
        getchar();
    }
    while (pbs > 0)
    {
        ft_printf("\nList_a dans qsA-pbs loop\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsA-rbs loop\n");
        ft_print_list(*lst_b);
        getchar();
        push(lst_a, lst_b);
        pbs--;
    }
    return (0);
}
