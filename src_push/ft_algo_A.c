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

#include "includes/ft_push_swap.h"

int     ft_partition_A(t_pile **lst_a, t_pile **lst_b, int len, int med, t_list **inst)
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
        if (head && head->content < med && j == 0)
        {
            ft_push_operations("pb", &head, lst_b, inst);
            j++;
        }
        if (head && head->content > med && j == 0)
        {
            ft_rot_operations("ra", &head, lst_b, inst);
            ras++;
            j++;
        }
        if (head && head->content == med && j == 0)
        {
            ft_push_operations("pb", &head, lst_b, inst);
            ft_rot_operations("rb", &head, lst_b, inst);
            j++;
        }
        i++;
        j = 0;
        /*ft_printf("ras: %d, med :%d, len: %d i :%d\n", ras, med, len, i);
        ft_printf("\nList_a dans qsA-partition\n");
        ft_print_list(head);
        ft_printf("\nList_b dans qsA-partition\n");
        ft_print_list(*lst_b);
        getchar();*/
    }
    ft_rev_rot_operations("rrb", &head, lst_b, inst);
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
    return(1);
    
}

int     ft_quick_sort_A(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    /*ft_printf("\nList_a dans qsA\nlen is %d\n", len);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsA\n");
    ft_print_list(*lst_b);
    getchar();*/
    int tmp;
    int med;
    int ras;
    int pbs;

    if (len < 2)
        return(1);
    med = ft_get_median(*lst_a, len);
    ras = ft_partition_A(lst_a, lst_b, len, med, inst);
    //dprintf(2, "done partitioning \n ras is :%d\n", ras);
    pbs = len - ras;
    //dprintf(2, "pbs is :%d\n", pbs);
    //dprintf(2, "len is :%d\n", len);
    tmp = ras;
    while (ras > 0)
    {
        ft_rev_rot_operations("rra", lst_a, lst_b, inst);
        ras--;
        /*ft_printf("\nPUTTING IT BACK \n ras is %d \n List_a dans qsA-ras loop\n", ras);
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsA-ras loop\n");
        ft_print_list(*lst_b);
        getchar();*/
    }
    ras = tmp;
    ft_quick_sort_A(lst_a, lst_b, ras, inst);
    ft_quick_sort_B(lst_a, lst_b, pbs, inst);
    while (pbs > 0)
    {

        ft_push_operations("pa", lst_a, lst_b, inst);
        pbs--;
        /*ft_printf("\nPUTTING IT BACK \n pbs is %d \n List_a dans qsA-pbs loop\n", pbs);
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsA-rbs loop\n");
        ft_print_list(*lst_b);
        getchar();*/
    }
    return (0);
}
