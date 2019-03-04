/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:07:55 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 10:55:56 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src_checker/includes/checker.h"

int				ft_prealable(char **argv)
{
	int opt;

	opt = ft_options(argv);
	if (opt < 0)
		return (opt);
	opt = ft_is_valid(argv, opt, 0, 0);
	if (opt < 0)
		ft_putstr("Error\n");
	return (opt);
}

void			ft_pile_add(t_pile **alst, t_pile *news)
{
	t_pile *current;

	if (alst && news)
	{
		current = *alst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = news;
	}
}

t_pile			*ft_pile_new(const int content, size_t content_size)
{
	t_pile	*tmp;

	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	if (!content)
	{
		tmp->content = 0;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		tmp->content = content;
		tmp->content_size = content_size;
		tmp->next = NULL;
		return (tmp);
	}
}

long long		ft_long_atoi(const char *str)
{
	long long	i;
	long long	tot;
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
