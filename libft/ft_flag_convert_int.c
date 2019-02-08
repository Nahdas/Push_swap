/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_convert_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:17:30 by alac              #+#    #+#             */
/*   Updated: 2018/12/13 16:21:28 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_convert_int(va_list *ap, char **tab, long long *x)
{
	if ((*tab)[7] == 0)
		*x = va_arg(*ap, int);
	if ((*tab)[7] == 1)
		*x = (short)va_arg(*ap, int);
	if ((*tab)[7] == 3)
		*x = (char)va_arg(*ap, int);
	if ((*tab)[7] == 2)
		*x = va_arg(*ap, long);
	if ((*tab)[7] == 4)
		*x = va_arg(*ap, long long);
}

int			ft_return_int(char *tab, int len, int count, long long x)
{
	if ((int)tab[6] == 0 && tab[5] == 0 && x == 0)
		return (0 + count);
	if (len > (int)tab[5] && len > (int)tab[6])
		return (len + count);
	if ((int)tab[5] >= len && (int)tab[5] > (int)tab[6])
		return ((int)tab[5] + count);
	return (count + (int)tab[6]);
}

int			ft_len_int(char **tab, long long x)
{
	long long	max;
	int			len;

	len = 0;
	max = -9223372036854775807 - 1;
	if (x < 0 && x > max)
	{
		x = -x;
		len = ft_nbrlen_base(x, 10) + 1;
		return (len);
	}
	if (x <= max)
	{
		x = -x;
		len = ft_nbrlen_base(x, 10);
		return (len);
	}
	if ((*tab)[1] == 1 && x >= 0)
		len = ft_nbrlen_base(x, 10) + 1;
	if (x <= max || (x >= 0 && (*tab)[1] != 1))
		len = ft_nbrlen_base(x, 10);
	return (len);
}

int			ft_not_minus(long long x, char *tab, int len, char *sign)
{
	ft_precision_int(x, tab, len, sign);
	if (x == 0 && tab[6] == 0 && tab[5] >= 1)
		ft_putchar(' ');
	else if (x != 0 || (x == 0 && tab[6] != 0))
		ft_putll_base(x, 10);
	return (0);
}
