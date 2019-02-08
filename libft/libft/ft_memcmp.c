/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:43:07 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/12 10:26:39 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*cop1;
	char	*cop2;

	i = 0;
	cop1 = (char*)s1;
	cop2 = (char*)s2;
	while (i < n)
	{
		if (cop1[i] != cop2[i])
			return ((unsigned char)cop1[i] - (unsigned char)cop2[i]);
		i++;
	}
	return (0);
}
