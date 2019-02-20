
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

int     ft_swap_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp(op, "sa") == 0)
    {
        write(1, "sa\n", 3);
        swap(lst_a);
    }
    if (ft_strcmp(op, "sb") == 0)
    {
        write(1, "sb\n", 3);
        swap(lst_b);
    }
    if (ft_strcmp(op, "ss") == 0)
    {
        write(1, "ss\n", 3);
        swap(lst_b);
        swap(lst_a);
    }
    return(0);
}

int     ft_push_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp(op, "pa") == 0)
    {
        write(1, "pa\n", 3);
        push(lst_a, lst_b);
    }
    if (ft_strcmp(op, "pb") == 0)
    {
        write(1, "pb\n", 3);
        push(lst_b, lst_a);
    }
    return(0);
}

int     ft_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp(op, "ra") == 0 || ft_strcmp(op, "rr") == 0)
    {
        write(1, "ra\n", 3);
        rotate(lst_a);
    }
    if (ft_strcmp(op, "rb") == 0|| ft_strcmp(op, "rr") == 0)
    {
        write(1, "rb\n", 3);
        rotate(lst_b);
    }
    return(0);
}

int     ft_rev_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp(op, "rra") == 0 || ft_strcmp(op, "rrr") == 0)
    {
        write(1, "rra\n", 4);
        rev_rotate(lst_a);
    }
    if (ft_strcmp(op, "rrb") == 0|| ft_strcmp(op, "rrr") == 0)
    {
        write(1, "rrb\n", 4);
        rev_rotate(lst_b);
    }
    return(0);
}

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
            push(lst_a, &head);
            j++;
        }
        if (head && head->content < med && j == 0)
        {
            rotate(&head);
            rbs++;
            j++;
        }
        if (head && head->content == med && j == 0)
        {
            push(lst_a, &head);
            rotate(lst_a);
            j++;
        }
        i++;
        j = 0;
        ft_printf("rbs: %d, med :%d, len: %d i :%d\n", rbs, med, len, i);
        ft_printf("\nList_a dans qsB-partition\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-partition\n");
        ft_print_list(head);
        getchar();
    }
    rev_rotate(lst_a);
    *lst_b = head;
    return(rbs);
}

int     ft_quick_sort_B(t_pile **lst_a, t_pile **lst_b, int len, int how)
{
    ft_printf("\nList_a dans qsB\n");
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB\n");
    ft_print_list(*lst_b);
    getchar();

    int med;
    int rbs;
    int pas;

    if (len < 2)
        return(1);
   // dprintf(2, "len is bigger than 2");
    med = ft_get_median(*lst_b, len);
    rbs = ft_partition_B(lst_a, lst_b, len, med);
    dprintf(2, "rbs is :%d\n", rbs);
    pas = len - rbs;
    dprintf(2, "pas is :%d\n", pas);
    ft_quick_sort_A(lst_a, lst_b, pas, how);
    ft_quick_sort_B(lst_a, lst_b, rbs, how);
    while (rbs > 0)
    {
        rev_rotate(lst_b);
        rbs--;
        ft_printf("\nList_a dans qsB-rbs loop\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-rbs loop\n");
        ft_print_list(*lst_b);
        getchar();
    }
    while (pas > 0)
    {
        ft_printf("\nList_a dans qsB-pas loop\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b dans qsB-pas loop\n");
        ft_print_list(*lst_b);
        getchar();
        push(lst_b, lst_a);
        pas--;
    }
    return (0);
}
