/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:04:02 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:07:46 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_u(va_list *ap, char *tab)
{
	unsigned long long	x;
	int					len;
	int					ret;

	if (tab[6] != -1)
		tab[3] = 0;
	ft_flag_convert(ap, &tab, &x);
	len = ft_unbrlen_base(x, 10);
	ret = ft_cas_0(tab, x);
	if (!(tab[2] = 0) && ret != -1)
		return (ret);
	ret = ft_ret(&tab, len);
	ft_fill_size_min(&tab, len);
	ft_fill_precision(&tab, len, x);
	ft_putull_base(x, 10);
	if (tab[0] == 1)
		while (tab[5] > tab[7] && tab[5] > len)
		{
			tab[5]--;
			if (tab[3] == 0)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	return (ret);
}
