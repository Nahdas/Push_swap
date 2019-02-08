/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:53:53 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/09 11:43:44 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cop1;
	char	*cop2;

	cop1 = (char*)dst;
	cop2 = (char*)src;
	i = 0;
	while (i < n)
	{
		cop1[i] = cop2[i];
		i++;
	}
	return (dst);
}
