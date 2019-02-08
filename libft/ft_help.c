/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:48:42 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:05:50 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_cas_0(char *tab, unsigned long long x)
{
	int ret;

	if (x == 0 && tab[6] == 0)
	{
		if (tab[5] > tab[2])
			ret = (int)tab[5];
		else
			ret = (int)tab[2];
		while (tab[5]-- > tab[2])
		{
			if (tab[3] == 0)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
		return (ret);
	}
	return (-1);
}

void		ft_flag_convert(va_list *ap, char **tab, unsigned long long *x)
{
	if ((*tab)[7] == 2)
		*x = va_arg(*ap, unsigned long);
	else if ((*tab)[7] == 4)
		*x = va_arg(*ap, unsigned long long);
	else
		*x = va_arg(*ap, unsigned int);
	if ((*tab)[7] == 1)
		*x = (unsigned short)(*x);
	if ((*tab)[7] == 3)
		*x = (unsigned char)(*x);
	if ((*tab)[6] == -1)
		(*tab)[6] = 1;
}

void		ft_fill_precision(char **tab, int len, unsigned long long x)
{
	(*tab)[7] = (*tab)[6];
	while (((*tab)[6] > len) || ((*tab)[2] == 1 && x != 0))
	{
		(*tab)[2] = 0;
		(*tab)[6]--;
		write(1, "0", 1);
	}
}

int			ft_ret(char **tab, int len)
{
	if ((*tab)[5] > len && (*tab)[5] >= (*tab)[6])
		return ((int)(*tab)[5]);
	else if ((*tab)[6] > len && (*tab)[6] >= (*tab)[5])
		return ((int)(*tab)[6]);
	else
		return (len);
}

void		ft_fill_size_min(char **tab, int len)
{
	(*tab)[1] = (*tab)[5];
	while ((*tab)[5] > (*tab)[6] && (*tab)[5] > len && (*tab)[0] != 1)
	{
		(*tab)[5]--;
		if ((*tab)[3] == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
	}
}
