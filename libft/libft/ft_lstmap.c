/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:51:20 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/15 11:54:38 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *nlst;
	t_list *tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(nlst = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		if (lst->next)
			lst = lst->next;
		first = nlst;
		while (lst && f)
		{
			tmp = f(lst);
			if (!(nlst->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			nlst = nlst->next;
			lst = lst->next;
		}
		return (first);
	}
	else
		return (NULL);
}
