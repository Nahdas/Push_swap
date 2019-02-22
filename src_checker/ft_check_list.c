

#include "includes/checker.h"

int     ft_check_list(t_pile *lst)
{
    t_pile *first;
    t_pile *back;

    first = lst;
    back = lst;
    while (lst->next != NULL)
    {
        while (first != NULL)
        {
            if (lst->content == first->content && lst != first)
            {
                ft_putstr("Error\n");
                return(0);
            }
            first = first->next;
        }
        first = back;
        lst = lst->next;
    }
    return(1);
}