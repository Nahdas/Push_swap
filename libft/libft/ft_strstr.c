/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:30:57 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/11 14:48:34 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j] && haystack[i + j] && needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
