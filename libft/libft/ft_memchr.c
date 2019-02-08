/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:35:43 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/09 11:43:17 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cop;

	i = 0;
	cop = (char*)s;
	while (i < n)
	{
		if (cop[i] == (char)c)
			return ((void*)&cop[i]);
		i++;
	}
	return (NULL);
}
