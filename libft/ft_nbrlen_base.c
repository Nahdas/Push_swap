/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:37:40 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:06:16 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_unbrlen_base(unsigned long long nb, unsigned long long base)
{
	unsigned long long i;
	unsigned long long j;
	unsigned long long x;

	x = 1000000000000000000;
	i = 1;
	j = 0;
	if (nb <= 9)
		return (1);
	if (nb >= x / base)
	{
		j++;
		nb /= base;
	}
	while (i <= nb)
	{
		j++;
		i *= base;
	}
	return ((int)j);
}

int				ft_nbrlen_base(long long nb, long long base)
{
	long long i;
	long long j;

	i = 1;
	j = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb /= base;
		j += 2;
		nb = -nb;
	}
	if (nb >= 100000000000000000)
	{
		j++;
		nb /= base;
	}
	while (i <= nb)
	{
		j++;
		i *= base;
	}
	return ((int)j);
}

int				ft_double_len_left(long double nb)
{
	long double		i;
	int				j;

	j = 0;
	i = 1;
	if (nb > -10 && nb < 10)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		nb /= 10;
		j += 2;
	}
	while (i <= nb)
	{
		j++;
		i *= 10;
	}
	return (j);
}
