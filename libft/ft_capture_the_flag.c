/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture_the_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:29:20 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:05:13 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_first_flag(char **tab, const char *format, int i)
{
	while (format[i] &&
			(format[i] == '#' ||
			format[i] == ' ' ||
			format[i] == '0' ||
			format[i] == '-' ||
			format[i] == '+'))
	{
		if (format[i] == '-')
			(*tab)[0] = 1;
		if (format[i] == '+')
			(*tab)[1] = 1;
		if (format[i] == '#')
			(*tab)[2] = 1;
		if (format[i] == '0')
			(*tab)[3] = 1;
		if (format[i] == ' ')
			(*tab)[4] = 1;
		i++;
	}
	return (i);
}

static int			ft_second_flag(char **tab, const char *format, int i)
{
	int		j;
	int		b;
	char	s[1000];

	j = 0;
	b = 0;
	ft_bzero(s, 1000);
	if (format[i] == '.')
	{
		b = 6;
		i++;
	}
	else
		b = 5;
	while (format[i] >= '0' && format[i] <= '9')
		s[j++] = format[i++];
	(*tab)[b] = ft_atoi(s);
	return (i);
}

static int			ft_third_flag(char **tab, const char *format, int i)
{
	if (format[i] == 'h')
	{
		(*tab)[7] = 1;
		if (format[++i] == 'h')
		{
			(*tab)[7] = 3;
			i++;
		}
	}
	if (format[i] == 'l')
	{
		(*tab)[7] = 2;
		if (format[++i] == 'l')
		{
			(*tab)[7] = 4;
			i++;
		}
	}
	if (format[i] == 'L')
	{
		(*tab)[7] = 5;
		i++;
	}
	return (i);
}

int					ft_is_flag(char c)
{
	if (c == '-' ||
			c == '+' ||
			c == '#' ||
			c == '0' ||
			c == ' ' ||
			(c >= '0' && c <= '9') ||
			c == '.' ||
			c == 'h' ||
			c == 'l' ||
			c == 'L')
		return (1);
	return (0);
}

int					ft_capture_the_flag(char **tab, const char *format,
		int *k, int *j)
{
	int i;

	*j += *k;
	i = *k + 1;
	ft_bzero((*tab), 8);
	(*tab)[6] = -1;
	while (ft_is_flag(format[i]) && format[i] != 'z' && format[i] != 'j')
	{
		i = ft_first_flag(tab, format, i);
		if (format[i] == '.' || (format[i] <= '9' && format[i] >= '0'))
			i = ft_second_flag(tab, format, i);
		i = ft_third_flag(tab, format, i);
	}
	*j -= i + 1;
	return (i);
}
