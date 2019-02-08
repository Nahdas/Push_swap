/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:07:55 by alac              #+#    #+#             */
/*   Updated: 2019/02/08 12:15:12 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long		ft_long_atoi(const char *str)
{
	long long	i;
	long long 	tot;
	int			sign;

	i = 0;
	tot = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		tot = tot * 10 + (str[i] - 48);
		i++;
	}
	return (tot * sign);
}
