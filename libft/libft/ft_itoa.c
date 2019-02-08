/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:59:28 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/03 16:31:37 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_countchar(int nb)
{
	int		c;
	long	n;
	int		i;

	n = (long)nb;
	i = 1;
	c = 0;
	if (nb == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		c++;
	}
	if (n > 1000000000 && n <= 2147483648)
	{
		c += 10;
		return (c);
	}
	while (i <= n)
	{
		i *= 10;
		c++;
	}
	return (c);
}

char			*ft_itoa(int n)
{
	long	nbr;
	char	*ret;
	int		i;

	nbr = (long)n;
	i = ft_countchar(n);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = '\0';
	if (n == 0)
	{
		ret[i] = '0';
		return (ret);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ret[0] = '-';
	}
	while (nbr != 0)
	{
		ret[i--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (ret);
}
