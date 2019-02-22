

#include "includes/ft_push_swap.h"

int     ft_swap_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp("sa", op) == 0)
    {
        write(1, "sa\n", 3);
        swap(lst_a);
    }
    if (ft_strcmp("sb", op) == 0)
    {
        write(1, "sb\n", 3);
        swap(lst_b);
    }
    if (ft_strcmp("ss", op) == 0)
    {
        write(1, "ss\n", 3);
        swap(lst_b);
        swap(lst_a);
    }
    return(0);
}

int     ft_push_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp("pa", op) == 0)
    {
        write(1, "pa\n", 3);
        push(lst_a, lst_b);
    }
    if (ft_strcmp("pb", op) == 0)
    {
        write(1, "pb\n", 3);
        push(lst_b, lst_a);
    }
    return(0);
}

int     ft_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp("ra", op) == 0)
    {
        write(1, "ra\n", 3);
        rotate(lst_a);
    }
    if (ft_strcmp("rb", op) == 0)
    {
        write(1, "rb\n", 3);
        rotate(lst_b);
    }
    if (ft_strcmp("rr", op) == 0)
    {
        write(1, "rr\n", 3);
        rotate(lst_a);
        rotate(lst_b);
    }
    return(0);
}

int     ft_rev_rot_operations(char *op, t_pile **lst_a, t_pile **lst_b)
{
    if (ft_strcmp(op, "rra") == 0)
    {
        write(1, "rra\n", 4);
        rev_rotate(lst_a);
    }
    if (ft_strcmp(op, "rrb") == 0)
    {
        write(1, "rrb\n", 4);
        rev_rotate(lst_b);
    }
    if (ft_strcmp(op, "rrr") == 0)
    {
        write(1, "rrr\n", 4);
        rev_rotate(lst_b);
        rev_rotate(lst_a);
    }
    return(0);
}