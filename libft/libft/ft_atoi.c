/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:51:15 by lmariott          #+#    #+#             */
/*   Updated: 2019/02/08 12:08:23 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_ok(const char *str)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '+')
	{
		if (str[i] == '+' && b > 0)
			return (-1);
		if (str[i] == '+')
			b++;
		i++;
	}
	if (b == 1 && str[i] == '-')
		return (-1);
	return (i);
}

int				ft_atoi(const char *str)
{
	int					a;
	unsigned long		ret;
	int					s;

	s = 0;
	ret = 0;
	if (is_ok(str) != -1)
		a = is_ok(str);
	else
		return (0);
	if (str[a] == '-' && s == 0)
	{
		s = 1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		ret *= 10;
		if ((str[a] > 47 && str[a] < 58))
			ret += str[a] - 48;
		a++;
	}
	if (s == 1)
		ret = -ret;
	return ((int)ret);
}
