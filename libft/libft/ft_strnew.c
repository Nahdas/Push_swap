/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:33:26 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/14 14:31:59 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (size == 0)
	{
		if (!(str = (char*)malloc(0)))
			return (0);
		return (str);
	}
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
