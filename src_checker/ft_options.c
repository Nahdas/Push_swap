/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:05:55 by alac              #+#    #+#             */
/*   Updated: 2019/02/08 13:15:37 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

int		ft_add(int x)
{
	int ind;
	int tot;

	ind = 32;
	ind = 35 - x;
	tot = 0;
	if (ind != 32 && ind != 13)
	{
		ft_putstr("options: c/v\n");
		return (-500);
	}
	if (ind == 32)
		tot++;
	if (ind == 13)
		tot = tot + 2;
	return (tot);
}

int		ft_is_opt(char *str, int count, int letter)
{
	int i;

	i = 1;
	while (str[i] && count >= 0)
	{
		if (str[i] > 122 || str[i] < 97)
		{
			if (str[i] < '0' || str[i] > '9' || letter != 0)
			{
				count = -500;
				return (-500);
			}
			else if (letter == 0)
				return (0);
		}
		else
		{
			count = ft_add((int)(str[i] - 96)) + count;
			letter++;
		}
		i++;
	}
	return (count);
}

int		ft_options(char **tab)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (tab[i] && count >= 0)
	{
		while (tab[i][j] && count >= 0)
		{
			if (tab[i][j] == '-')
				count = count + ft_is_opt(&tab[i][j], 0, 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
