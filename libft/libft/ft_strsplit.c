/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:50:30 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 16:32:22 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_is_word(char s, char c)
{
	if (s == c || s == '\0')
		return (0);
	else
		return (1);
}

static	int			ft_count_words(const char *s, char c)
{
	int i;
	int b;
	int co;

	co = 0;
	b = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_is_word(s[i], c) == 0)
			b = 1;
		if (ft_is_word(s[i], c) == 1)
			if (b == 1)
			{
				b = 0;
				co++;
			}
		i++;
	}
	return (co);
}

static	int			ft_strlenw(const char *s, char c)
{
	int		i;
	char	d;

	d = c;
	i = 0;
	if (s)
		while (ft_is_word(s[i], d) == 1)
			i++;
	return (i);
}

static	char		**ft_shit(int *tab, char **ret, const char *s, char c)
{
	while (s[tab[0]] != '\0')
	{
		if (ft_is_word(s[tab[0]], c) == 0)
			tab[1] = 0;
		if (ft_is_word(s[tab[0]], c) == 1 && tab[1] == 0)
		{
			if (!(ret[++tab[2]] = (char*)malloc(ft_strlenw(&s[tab[0]], c) + 1)))
				return (NULL);
			ret[tab[2]][tab[1]++] = s[tab[0]];
			ret[tab[2]][tab[1]] = '\0';
		}
		tab[0]++;
		if (ft_is_word(s[tab[0]], c) == 1 && tab[1] > 0)
		{
			ret[tab[2]][tab[1]++] = s[tab[0]];
			ret[tab[2]][tab[1]] = '\0';
		}
	}
	ret[++tab[2]] = NULL;
	return (ret);
}

char				**ft_strsplit(const char *s, char c)
{
	int		tab[3];
	char	**ret;
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] == c)
			i++;
	}
	if (s == NULL || s[0] == '\0')
	{
		if (!(ret = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		ret[0] = NULL;
		return (ret);
	}
	if (!(ret = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	tab[1] = 0;
	tab[0] = 0;
	tab[2] = -1;
	ret = ft_shit(tab, ret, s, c);
	return (ret);
}
