
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

int     ft_partition_B(t_pile **lst_a, t_pile **lst_b, int len, int med)
{
    t_pile *head;
    int i;
    int j;
    int rbs;

    head = *lst_b;
    i = 0;
    j = 0;
    rbs = 0;
    while (i < len)
    {
        if (head && head->content > med && j == 0)
        {
            ft_push_operations("pa", lst_a, &head);
            j++;
        }
        if (head && head->content < med && j == 0)
        {
            ft_rot_operations("rb", lst_a, &head);
            rbs++;
            j++;
        }
        if (head && head->content == med && j == 0)
        {
            ft_push_operations("pa", lst_a, &head);
            ft_rot_operations("ra", lst_a, &head);
            j++;
        }
        i++;
        j = 0;
        /*ft_printf("rbs: %d, med :%d, len: %d i :%d\n", rbs, med, len, i);
        ft_printf("\nList_a dans qsB-partition\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-partition\n");
        ft_print_list(head);
        getchar();*/
    }
    ft_rev_rot_operations("rra", lst_a, &head);
    *lst_b = head;
    return(rbs);
}

int     ft_quick_sort_B(t_pile **lst_a, t_pile **lst_b, int len, int how)
{
    /*ft_printf("\nList_a dans qsB avec len:%d\n", len);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB\n");
    ft_print_list(*lst_b);
    getchar();*/

    int tmp;
    int med;
    int rbs;
    int pas;

    if (len < 2)
        return(1);
    med = ft_get_median(*lst_b, len);
    rbs = ft_partition_B(lst_a, lst_b, len, med);
    //dprintf(2, "DONE PARTITIONING len is %d\n", len);
   // dprintf(2, "rbs is :%d\n", rbs);
    pas = len - rbs;
    //dprintf(2, "pas is :%d\n", pas);
    tmp = rbs;
    while (rbs > 0)
    {
        ft_rev_rot_operations("rrb", lst_a, lst_b);
        rbs--;
        /*ft_printf("\nPUTTING IT BACK \n rbs is %d \nList_a dans qsB-rbs loop\n", rbs);
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-rbs loop\n");
        ft_print_list(*lst_b);
        getchar();*/
    }
    rbs = tmp;
    ft_quick_sort_B(lst_a, lst_b, rbs, how);
    ft_quick_sort_A(lst_a, lst_b, pas, how);
    while (pas > 0)
    {
        /*ft_printf("\nPUTTTING IT BACK\npas is %d\nList_a dans qsB-pas loop\n", pas);
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-pas loop\n");
        ft_print_list(*lst_b);
        getchar();*/
        ft_push_operations("pb", lst_a, lst_b);
        pas--;
    }
    return (0);
}