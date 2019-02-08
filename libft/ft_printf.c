/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:52:17 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/17 18:06:39 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_creat_tab(void)
{
	char	*tab;
	int		i;

	if (!(tab = (char *)malloc(sizeof(char) * 8)))
		return (0);
	i = 0;
	ft_bzero(tab, 8);
	tab[6] = -1;
	return (tab);
}

void			ft_init_part_printf(char **tab, int *i, int *j)
{
	*tab = ft_creat_tab();
	*i = -1;
	*j = 0;
}

int				ft_ret_cas(int i, int j, t_list_f *list, char **tab)
{
	ft_del_list_n_tab(list, tab);
	return (i + j + 1);
}

int				ft_printf_part(const char *format, t_list_f *head,
		t_list_f *list, va_list *ap)
{
	char		*tab;
	int			i;
	int			j;

	ft_init_part_printf(&tab, &i, &j);
	while (format[++i])
	{
		head = list;
		if (format[i] == '%')
		{
			i = ft_capture_the_flag(&tab, format, &i, &j);
			if (format[i] == '\0')
				return (ft_ret_cas(i, j, list, &tab));
			while (head && head->c != format[i])
				head = head->next;
			if (head)
				j += (head->f)(ap, tab);
			else
				j += ft_any(format[i], tab);
		}
		else
			write(1, &format[i], 1);
	}
	ft_del_list_n_tab(list, &tab);
	return (i + j);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list_f	*head;
	t_list_f	*list;
	int			ret;

	if (!format)
		return (0);
	va_start(ap, format);
	list = NULL;
	head = NULL;
	list = ft_make_list_f();
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (0);
	ret = ft_printf_part(format, head, list, &ap);
	va_end(ap);
	free(head);
	return (ret);
}
