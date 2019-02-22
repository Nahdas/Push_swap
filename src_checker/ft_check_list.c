/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:04:31 by alac              #+#    #+#             */
/*   Updated: 2019/02/22 18:04:46 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
                write(2,"Error\n", 6);
                return(0);
            }
            first = first->next;
        }
        first = back;
        lst = lst->next;
    }
    return(1);
}
