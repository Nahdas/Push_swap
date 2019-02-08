/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:59:09 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:05:40 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_size_f(char **tab)
{
	while ((*tab)[0] != 1 && (int)(*tab)[5] > (*tab)[7])
	{
		if ((*tab)[3] != 1)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		((*tab)[5])--;
	}
}

void		ft_fill_precision_f(char **tab, long double x)
{
	int tmp;

	if ((*tab)[6] != 0)
	{
		write(1, ".", 1);
		while ((*tab)[6] != 1)
		{
			x *= 10;
			ft_putnbr((int)x % 10);
			x -= (int)x;
			((*tab)[6])--;
		}
		x *= 10;
		tmp = (int)x % 10;
		if ((int)(x * 10) % 10 >= 5)
			tmp++;
		ft_putnbr(tmp);
	}
}

int			ft_double_f(va_list *ap, char *tab)
{
	long double			x;
	int					len;

	if (tab[6] == -1)
		tab[6] = 6;
	if (tab[7] == 5 || tab[7] == 4)
		x = va_arg(*ap, long double);
	else
		x = va_arg(*ap, double);
	len = ft_double_len_left(x);
	tab[7] = tab[6] + len + tab[1] + tab[4] + 1;
	tab[2] = tab[5];
	ft_fill_size_f(&tab);
	if (tab[1] == 1 && x >= 0)
		write(1, "+", 1);
	if (x < 0 && (x = -x))
		write(1, "-", 1);
	if (tab[4] == 1)
		write(1, " ", 1);
	ft_putnbr((int)x);
	x -= (int)x;
	ft_fill_precision_f(&tab, x);
	ft_fill_size_f(&tab);
	return (tab[2] > tab[7] ? tab[2] : tab[7]);
}
