

#include "includes/ft_push_swap.h"

int         ft_sort_three(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
    t_pile *first;
    t_pile *sec;
    t_pile *third;

    first = *lst_a;
    sec = first->next;
    third = sec->next;
    if (first->content > sec->content && sec->content < third->content && third->content < first->content)
        ft_rot_operations("ra", lst_a, lst_b, inst);
    if (first->content < sec->content && sec->content > third->content && third->content < first->content)
        ft_rev_rot_operations("rra", lst_a, lst_b, inst);
    if (first->content > sec->content && sec->content > third->content && third->content < first->content)
    {
        ft_swap_operations("sa", lst_a, lst_b, inst);
        ft_rev_rot_operations("rra", lst_a, lst_b, inst);
    }
    if (first->content < sec->content && sec->content > third->content && third->content > first->content)
    {
        ft_rev_rot_operations("rra", lst_a, lst_b, inst);
        ft_swap_operations("sa", lst_a, lst_b, inst);
    }
    if (first->content > sec->content && sec->content < third->content && third->content > first->content)
        ft_swap_operations("sa", lst_a, lst_b, inst);
    return(1);
}

int         ft_sort_four(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
    int ras;
    int min;
    int max;
    int quick = 0;

    ras = 0;
    min = ft_get_min(*lst_a, 4);
    max = ft_get_max(*lst_a, 4);
    while ((*lst_a)->content == min || (*lst_a)->content == max)
        ft_rot_operations("ra", lst_a, lst_b, inst);
    ft_push_operations("pb", lst_a, lst_b, inst);
    ft_sort_three(lst_a, lst_b, inst);
    while ((*lst_a)->content < (*lst_b)->content)
    {
        ft_rot_operations("ra", lst_a, lst_b, inst);
        ras++;
    }
    ft_push_operations("pa", lst_a, lst_b, inst);
    while (ras > 0)
    {
        if (ras == ft_get_size(*lst_a))
            break;
        else if (ras > ft_get_size(*lst_a))
            ras = ras - ft_get_size(*lst_a);
        if (ras > 2 || quick == 1)
        {
            if (quick == 0)
                ras = ft_get_size(*lst_a) - ras;
            quick = 1;
            ft_rot_operations("ra", lst_a, lst_b, inst);
        }
        else
            ft_rev_rot_operations("rra", lst_a, lst_b, inst);
        ras--;
    }
    return(1);
}

int         ft_sort_five(t_pile **lst_a, t_pile **lst_b, t_list **inst)
{
    int ras;
    int min;
    int max;
    int quick = 0;

    ras = 0;
    min = ft_get_min(*lst_a, 5);
    max = ft_get_max(*lst_a, 5);
    while ((*lst_a)->content == min || (*lst_a)->content == max)
        ft_rot_operations("ra", lst_a, lst_b, inst);
    ft_push_operations("pb", lst_a, lst_b, inst);
    while ((*lst_a)->content == min || (*lst_a)->content == max)
        ft_rot_operations("ra", lst_a, lst_b, inst);
    ft_push_operations("pb", lst_a, lst_b, inst);
    ft_sort_three(lst_a, lst_b, inst);
    while ((*lst_a)->content < (*lst_b)->content)
    {
        ft_rot_operations("ra", lst_a, lst_b, inst);
        ras++;
    }
    ft_push_operations("pa", lst_a, lst_b, inst);
    while (ras > 0)
    {
        if (ras == ft_get_size(*lst_a))
            break;
        else if (ras > ft_get_size(*lst_a))
            ras = ras - ft_get_size(*lst_a);
        if (ras > 2 || quick == 1)
        {
            if (quick == 0)
                ras = ft_get_size(*lst_a) - ras;
            quick = 1;
            ft_rot_operations("ra", lst_a, lst_b, inst);
        }
        else
            ft_rev_rot_operations("rra", lst_a, lst_b, inst);
        ras--;
    }
    while ((*lst_a)->content < (*lst_b)->content)
    {
        ft_rot_operations("ra", lst_a, lst_b, inst);
        ras++;
    }
    ft_push_operations("pa", lst_a, lst_b, inst);
    while (ras > 0)
    {
        if (ras == ft_get_size(*lst_a))
            break;
        else if (ras > ft_get_size(*lst_a))
            ras = ras - ft_get_size(*lst_a);
        if (ras > 2 || quick == 1)
        {
            if (quick == 0)
                ras = ft_get_size(*lst_a) - ras;
            quick = 1;
            ft_rot_operations("ra", lst_a, lst_b, inst);
        }
        else
            ft_rev_rot_operations("rra", lst_a, lst_b, inst);
        ras--;
    }
    return(1);
}

int         ft_simple_sort(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    t_pile *head;
    t_pile *follow;

    if (ft_that_is_sorted(*lst_a, len))
        return(1);
    follow = NULL;
    head = (*lst_a);
    if (head->next != NULL)
        follow = head->next;
    if (len == 2)
    {
        if (head->content > follow->content)
            ft_swap_operations("sa", &head, lst_b, inst);
        return(1);
    }
    if (len == 3)
        return(ft_sort_three(lst_a, lst_b, inst));
    if (len == 4)
        return(ft_sort_four(lst_a, lst_b, inst));
    if (len == 5)
        return(ft_sort_five(lst_a, lst_b, inst));
    return(1);
}