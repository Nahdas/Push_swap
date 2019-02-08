/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:18:50 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/12 15:31:56 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void		*ptr;
	char		*ptr2;
	size_t		i;

	i = 0;
	if (size == 0)
		return (NULL);
	if (!(ptr = malloc(sizeof(char) * size)))
		return (NULL);
	ptr2 = (char*)ptr;
	while (i < size)
		ptr2[i++] = '\0';
	return (ptr);
}
