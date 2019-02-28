/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:04:10 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 17:27:00 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *str, const char c)
{
	int		len;
	int		i;
	char	*copy;

	len = ft_strclen(str, c);
	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
