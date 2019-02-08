/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:22:26 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/13 15:11:13 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		tab[2];
	char	*ret;

	tab[1] = 0;
	tab[0] = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char*)s2);
	if (s2 == NULL)
		return ((char*)s1);
	while (s1[tab[0]] != '\0')
		tab[0]++;
	while (s2[tab[1]] != '\0')
		tab[1]++;
	if (!(ret = (char *)malloc(sizeof(char) * (tab[0] + tab[1]))))
		return (0);
	tab[0] = -1;
	while (s1[++tab[0]] != '\0')
		ret[tab[0]] = s1[tab[0]];
	tab[1] = -1;
	while (s2[++tab[1]] != '\0')
		ret[tab[0] + tab[1]] = s2[tab[1]];
	ret[tab[0] + tab[1]] = '\0';
	return (ret);
}
