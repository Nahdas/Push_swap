/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:11:56 by alac              #+#    #+#             */
/*   Updated: 2019/02/25 14:12:00 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int     ft_get_min(t_pile *lst, int len)
{
    t_pile *head;
    t_pile *copy;
    int min;

    ft_copy_list(lst, &copy, len);
    head = copy;
    min = head->content;
    while (head != NULL)
    {
        if (head->content < min)
            min = head->content;
        head = head->next;
    }
    ft_del_list(&copy);
    return(min);
}

int     ft_get_max(t_pile *lst, int len)
{
    t_pile *head;
    t_pile *copy;
    int max;

    ft_copy_list(lst, &copy, len);
    head = copy;
    max = head->content;
    while (head != NULL)
    {
        if (head->content > max)
            max = head->content;
        head = head->next;
    }
    ft_del_list(&copy);
    return(max);
}

int     ft_that_is_unsorted(t_pile *lst, int len)
{
    t_pile *tmp;
    t_pile *copy;

    ft_copy_list(lst, &copy, len);
    if (copy->next != NULL)
        tmp = copy->next;
    else
        tmp = NULL;
    while (tmp != NULL)
    {
        if (tmp->content > copy->content)
            return(0);
        copy = tmp;
        tmp = tmp->next;
    }
    ft_del_list(&copy);
    return(1);
}

int     ft_that_is_sorted(t_pile *lst, int len)
{
    t_pile *tmp;
    t_pile *copy;

    ft_copy_list(lst, &copy, len);
    if (copy->next != NULL)
        tmp = copy->next;
    else
        tmp = NULL;
    while (tmp != NULL)
    {
        if (tmp->content < copy->content)
            return(0);
        copy = tmp;
        tmp = tmp->next;
    }
    ft_del_list(&copy);
    return(1);
}

int     ft_select_sort_A(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    int min;
    int ras;
    t_pile *node;

    if (len <= 1 || ft_that_is_sorted(*lst_a, len))
    {
        /*printf("AAA SORTED lst_a len :%d\n",len);
        ft_print_list(*lst_a);
        ft_printf("\nList_b\n");
        ft_print_list(*lst_b);
        getchar();*/
        return (1);
    }
    min = ft_get_min(*lst_a, len);
    /*ft_printf("\nSelect Sort AAA Debut \n min is %d len is %d\nList_a\n", min, len);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB-rbs loop\n");
    ft_print_list(*lst_b);
    getchar();*/
    node = *lst_a;
    ras = 0;
    while (node->content != min)
    {
        ft_rot_operations("ra", &node, lst_b, inst);
        ras++;
        /*ft_printf("looking for min, list_a\n");
        ft_print_list(node);
        ft_printf("\nList_b\n");
        ft_print_list(*lst_b);
        getchar();*/
    }
    ft_push_operations("pb", &node, lst_b, inst);
    /*ft_printf("remove min , list_a\n");
    ft_print_list(node);
    ft_printf("\nList_b\n");
    ft_print_list(*lst_b);
    getchar();*/
    while (ras > 0)
    {
        /*ft_printf("put back in place, ras is %d list_a\n", ras);
        ft_print_list(node);
        ft_printf("\nList_b\n");
        ft_print_list(*lst_b);
        getchar();*/
        ft_rev_rot_operations("rra", &node, lst_b, inst);
        ras--;
    }
    ft_push_operations("pa", &node, lst_b, inst);
    /*ft_printf("put back in place, list_a\n");
    ft_print_list(node);
    ft_printf("\nList_b\n");
    ft_print_list(*lst_b);
    getchar();*/
    *lst_a = node;
    /*ft_printf("\nSelect Sort AAA END \n min is %d len is %d\nList_a\n", min, len);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB-rbs loop\n");
    ft_print_list(*lst_b);
    getchar();*/
    ft_rot_operations("ra", &node, lst_b, inst);
    ft_select_sort_A(&node, lst_b, --len, inst);
    ft_rev_rot_operations("rra", &node, lst_b, inst);
    return(0);
}

int     ft_select_sort_B(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    int min;
    int rbs;
    t_pile *node;

    if (len <= 1 || ft_that_is_unsorted(*lst_b, len))
    {
        /*printf("BBB SORTED lst_a len :%d\n",len);
        ft_print_list(*lst_a);
        ft_printf("\nList_b\n");
        ft_print_list(*lst_b);
        getchar();*/
        return(1);
    }
    min = ft_get_max(*lst_b, len);
    /*ft_printf("\nSelect Sort BBB Debut \n min is %d len is %d\nList_a\n", min, len);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB-rbs loop\n");
    ft_print_list(*lst_b);
    getchar();*/
    node = *lst_b;
    rbs = 0;
    while (node->content != min)
    {
        /*ft_printf("looking for min, list_a\n");
        ft_print_list(*lst_a);
        ft_printf("\nList_b\n");
        ft_print_list(node);
        getchar();*/
        ft_rot_operations("rb", lst_a, &node, inst);
        rbs++;
    }
    ft_push_operations("pa", lst_a, &node, inst);
    /*ft_printf("remove min , list_a\n");
    ft_print_list(*lst_a);
    ft_printf("\nList_b\n");
    ft_print_list(node);
    getchar();*/
    while (rbs > 0)
    {
        /*ft_printf("put back in place, rbs is %d list_a\n", rbs);
        ft_print_list(*lst_a);
        ft_printf("\nList_b\n");
        ft_print_list(node);
        getchar();*/
        ft_rev_rot_operations("rrb", lst_a, &node, inst);
        rbs--;
    }
    ft_push_operations("pb", lst_a, &node, inst);
    *lst_b = node;
    /*ft_printf("\nSelect Sort BBB END \n min is %d \nList_a dans qsB-rbs loop\n", min);
    ft_print_list(*lst_a);
    ft_printf("\nList_b dans qsB-rbs loop\n");
    ft_print_list(*lst_b);
    getchar();*/
    ft_rot_operations("rb", lst_a, &node, inst);
    ft_select_sort_B(lst_a, &node, --len, inst);
    ft_rev_rot_operations("rrb", lst_a, &node, inst);
    return(0);
}