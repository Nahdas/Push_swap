/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:22:43 by alac              #+#    #+#             */
/*   Updated: 2018/12/17 18:05:57 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size_int(char *tab, int len, char *sign, long long x)
{
	int i;

	i = 0;
	if (((tab[1] == 1 || (*sign) == '-') && tab[5] > tab[6] && tab[5] > len
			&& tab[6] != -1 && tab[6] > len - 1) ||
			(tab[4] == 1 && tab[1] != 1 && x >= 0 &&
			(tab[5] <= tab[6] || tab[5] <= len || tab[6] == -1)))
		i++;
	if (tab[3] == 1 && tab[6] == -1 && i == 0 && (*sign) != 0)
	{
		ft_putchar((*sign));
		(*sign) = 0;
	}
	if (tab[5] > len && tab[5] > tab[6])
		while (i < tab[5] - len && i < tab[5] - tab[6])
		{
			if (tab[3] == 1 && tab[0] != 1 && tab[6] == -1)
				ft_putchar('0');
			if (tab[3] != 1 || (tab[3] == 1 && tab[0] == 1) ||
				(tab[3] == 1 && tab[6] != -1))
				ft_putchar(' ');
			i++;
		}
	return (0);
}

int				ft_precision_int(long long x, char *tab, int len, char *sign)
{
	int i;

	i = 0;
	if (((*sign) == '+' || (*sign) == '-') && (tab[6] != -1 || tab[3] != 1 ||
		(tab[3] == 1 && tab[0] == 1) || (tab[3] == 1 && tab[4] == 1)))
	{
		ft_putchar(*sign);
		(*sign) = 0;
	}
	while (i < tab[6] - ft_nbrlen_base(x, 10))
	{
		ft_putchar('0');
		i++;
	}
	i = len;
	return (0);
}

static int		ft_negative_int(char **tab, long long x, char *sign, int *count)
{
	int			len;
	long long	max;

	max = -9223372036854775807 - 1;
	len = 0;
	if (x < 0 && x > max)
	{
		(*sign) = '-';
		x = -x;
		len = ft_nbrlen_base(x, 10) + 1;
		if ((*tab)[6] > len && (*tab)[6] > (*tab)[5])
			(*count)++;
		if ((*tab)[0] == 1)
		{
			ft_precision_int(x, *tab, len, sign);
			ft_putll_base(x, 10);
		}
	}
	if (x <= max)
		len = ft_nbrlen_base(x, 10);
	return (len);
}

static int		ft_positive_int(char **tab, long long x, char *sign, int *count)
{
	int len;

	len = ft_len_int(tab, x);
	if (x >= 0)
	{
		if ((*tab)[1] == 1 && x >= 0)
			*sign = '+';
		if ((*tab)[4] == 1 && (*tab)[1] != 1 && x >= 0 &&
			((*tab)[5] <= (*tab)[6] || (*tab)[5] <= len || (*tab)[6] == -1))
		{
			ft_putchar(' ');
			(*count)++;
		}
		if ((*tab)[0] == 1)
		{
			ft_precision_int(x, *tab, len, sign);
			if (x == 0 && tab[6] == 0)
				ft_putchar(' ');
			else if (x != 0 || (x == 0 && (*tab)[6] == -1))
				ft_putll_base(x, 10);
		}
	}
	return (len);
}

int				ft_int(va_list *ap, char *tab)
{
	long long	x;
	int			i;
	int			len;
	char		sign;
	int			count;

	len = 0;
	i = 0;
	sign = 0;
	count = 0;
	ft_flag_convert_int(ap, &tab, &x);
	if (!tab)
		return (0);
	len = ft_negative_int(&tab, (long long)x, &sign, &count);
	len = ft_positive_int(&tab, (long long)x, &sign, &count);
	if (x < 0)
		x = -x;
	ft_size_int(tab, len, &sign, (long long)x);
	if (tab[0] != 1)
		ft_not_minus((long long)x, tab, len, &sign);
	return (ft_return_int(tab, len, count, x));
}
