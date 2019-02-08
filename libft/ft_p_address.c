/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:04:02 by alac              #+#    #+#             */
/*   Updated: 2018/12/17 18:06:25 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size(long long x, char *tab)
{
	int i;

	i = 0;
	if (tab[5] >= ft_nbrlen_base(x, 10) + 2)
	{
		while (i < (int)tab[5] - (ft_nbrlen_base(x, 16) + 2) &&
				i < (int)tab[5] - (tab[6] + 2))
		{
			if (tab[3] != 1)
				ft_putchar(' ');
			else
				ft_putchar('0');
			i++;
		}
	}
	return (0);
}

static void		ft_precision(char *tab, long long x)
{
	while (tab[6] > ft_unbrlen_base(x, 16))
	{
		write(1, "0", 1);
		tab[6]--;
	}
}

static int		ft_preceding_char(char *tab, long long x)
{
	if (tab[0] == 1)
	{
		ft_putstr("0x");
		ft_precision(tab, (long long)x);
		ft_putull_base_min((unsigned long long)x, 16);
		return (1);
	}
	return (0);
}

static void		ft_part_p(void *x, char *tab)
{
	ft_putstr("0x");
	ft_precision(tab, (long long)x);
	if (tab[6] != 0 || x != 0)
		ft_putull_base_min((unsigned long long)x, 16);
}

int				ft_p_address(va_list *ap, char *tab)
{
	void		*x;
	int			i;
	int			len;

	i = 0;
	if (!tab)
		return (0);
	if (tab[6] == -1)
		tab[6] = 1;
	tab[7] = tab[6] + 2;
	x = va_arg(*ap, void *);
	i = ft_preceding_char(tab, (long long)x);
	if (tab[3] != 1)
		ft_size((long long)x, tab);
	if (i != 1)
		ft_part_p(x, tab);
	if (tab[3] == 1)
		ft_size((long long)x, tab);
	len = ft_unbrlen_base((long long)x, 16) + 2;
	if (!x && tab[7] == 2)
		len = 2;
	if (len > tab[7])
		return (len > tab[5] ? len : tab[5]);
	else
		return (tab[7] > tab[5] ? tab[7] : tab[5]);
}
