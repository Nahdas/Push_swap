/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:28:51 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 16:32:01 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_condition(const char *s, int i, int j)
{
	char *ret;

	if (s[i] != '\0')
	{
		if (!(ret = (char*)malloc(sizeof(char) * (j - i + 1))))
			return (NULL);
	}
	else
	{
		if (!(ret = (char*)malloc(sizeof(char) * 0)))
			return (NULL);
	}
	return (ret);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	k = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while (s[j] != '\0')
		j++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
		j--;
	j++;
	if (!(ret = ft_condition(s, i, j)))
		return (NULL);
	while (i < j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}
