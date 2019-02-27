
#include "includes/ft_push_swap.h"

int         ft_get_insert_index_A(t_pile *head, int item, int len)
{
    int i;

    i = 0;
    while (head->content > item && i < len)
    {
        rev_rotate(&head);
        i++;
    }
    i--;
    return(i);
}

int         ft_insert_sort_A(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    t_pile *head;
    t_pile *follow;
    int ras;
    int tmp;
    int ind;
    int i;

    ft_copy_list(*lst_a, &head, len);
    follow = head->next;
    ras = 1;
    i = 0;
    /*ft_printf("\nDebut\n");
    ft_printf("\n A \n");
    ft_print_list(*lst_a);
    ft_printf("\n B \n");
    ft_print_list(*lst_b);
    getchar();*/
    while (follow != NULL)
    {
        if (head->content > follow->content)
        {
            ft_del_list(&head);
            tmp = ras;
            while (ras > 0)
            {
                ft_rot_operations("ra", lst_a, lst_b, inst);
                ras--;
                /*ft_printf("\nFinding next value ras:%d\n", ras);
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
            }
            ft_push_operations("pb", lst_a, lst_b, inst);
            ft_rev_rot_operations("rra", lst_a, lst_b, inst);
            ft_copy_list(*lst_a, &head, len);
            ind = ft_get_insert_index_A(head, (*lst_b)->content, tmp);
            while (i < ind)
            {
                /*ft_printf("\nFinding right spot i:%d, ind:%d\n", i, ind);
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
                ft_rev_rot_operations("rra", lst_a, lst_b, inst);
                i++;
            }
            ft_push_operations("pa", lst_a, lst_b, inst);
            while (tmp - ind > 1)
            {
                /*ft_printf("\nPutting back together\n");
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
                ft_rev_rot_operations("rra", lst_a, lst_b, inst);
                tmp--;
            }
            ft_del_list(&head);
            /*ft_printf("\nFINAL\n");
            ft_printf("\n A \n");
            ft_print_list(*lst_a);
            ft_printf("\n B \n");
            ft_print_list(*lst_b);
            getchar();*/
            ft_insert_sort_A(lst_a, lst_b, len, inst);
            return(1);
        }
        ras++;
        head = follow;
        follow = follow->next;
    }
    ft_del_list(&head);
    return(1);
}

int         ft_get_insert_index_B(t_pile *head, int item, int len)
{
    int i;

    i = 0;
    while (head->content < item && i < len)
    {
        rev_rotate(&head);
        i++;
    }
    i--;
    return(i);
}

int         ft_insert_sort_B(t_pile **lst_a, t_pile **lst_b, int len, t_list **inst)
{
    t_pile *head;
    t_pile *follow;
    int rbs;
    int tmp;
    int ind;
    int i;

    ft_copy_list(*lst_b, &head, len);
    follow = head->next;
    rbs = 1;
    i = 0;
    /*ft_printf("\nDebut len %d\n", len);
    ft_printf("\n A \n");
    ft_print_list(*lst_a);
    ft_printf("\n B \n");
    ft_print_list(*lst_b);
    getchar();*/
    while (follow != NULL)
    {
        if (head->content < follow->content)
        {
            ft_del_list(&head);
            tmp = rbs;
            while (rbs > 0)
            {
                ft_rot_operations("rb", lst_a, lst_b, inst);
                rbs--;
                /*ft_printf("\nFinding next value rbs:%d\n", rbs);
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
            }
            ft_push_operations("pa", lst_a, lst_b, inst);
            ft_rev_rot_operations("rrb", lst_a, lst_b, inst);
            ft_copy_list(*lst_b, &head, len);
            ind = ft_get_insert_index_B(head, (*lst_b)->content, tmp);
            while (i < ind)
            {
                /*ft_printf("\nFinding right spot i:%d, ind:%d\n", i, ind);
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
                ft_rev_rot_operations("rrb", lst_a, lst_b, inst);
                i++;
            }
            ft_push_operations("pb", lst_a, lst_b, inst);
            while (tmp - ind > 2)
            {
                /*ft_printf("\nPutting back together\n");
                ft_printf("\n A \n");
                ft_print_list(*lst_a);
                ft_printf("\n B \n");
                ft_print_list(*lst_b);
                getchar();*/
                ft_rev_rot_operations("rrb", lst_a, lst_b, inst);
                tmp--;
            }
            ft_del_list(&head);
            /*ft_printf("\nFINAL len %d\n", len);
            ft_printf("\n A \n");
            ft_print_list(*lst_a);
            ft_printf("\n B \n");
            ft_print_list(*lst_b);
            getchar();*/
            ft_insert_sort_B(lst_a, lst_b, len, inst);
            return(1);
        }
        rbs++;
        head = follow;
        follow = follow->next;
    }
    ft_del_list(&head);
    return(1);
}