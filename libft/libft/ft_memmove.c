/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:24:46 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/12 15:33:27 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cop1;
	char	*cop2;

	i = -1;
	cop1 = (char*)dst;
	cop2 = (char*)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		while (++i < len)
			cop1[i] = cop2[i];
	else
	{
		while (len > 0)
		{
			cop1[len - 1] = cop2[len - 1];
			len--;
		}
	}
	return (dst);
}
