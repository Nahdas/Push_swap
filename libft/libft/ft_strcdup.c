/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:57:45 by alac              #+#    #+#             */
/*   Updated: 2018/11/23 13:46:04 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcdup(const char *s1, const char c)
{
	int		len;
	int		i;
	char	*copy;

	i = 0;
	len = ft_strclen(s1, c);
	if (!(copy = (char *)malloc(sizeof(copy) * (len + 1))))
		return (0);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
