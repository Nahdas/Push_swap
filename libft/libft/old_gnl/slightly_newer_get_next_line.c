/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:14:33 by alac              #+#    #+#             */
/*   Updated: 2019/02/28 17:31:55 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move(char **str)
{
	char	*end;

	end = ft_strchr(*str, '\n') + 1;
	free(*str);
	*str = ft_strdup(end);
	return (*str);
}

void	ft_strclr(char **str)
{
	int i;

	i = 0;
	if (*str)
	{
		while (*str[i])
		{
			*str[i] = '\0';
			i++;
		}
		free(*str);
		str = NULL;
	}
}

char	*ft_realloc(char *str, int old_size, int new_size)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (new_size + 1));
	while (i < old_size)
	{
		copy[i] = str[i];
		i++;
	}
	while (i <= new_size)
	{
		copy[i] = '\0';
		i++;
	}
	if (str)
		free(str);
	return (copy);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;
	int				ret;
	int				i;

	tmp = NULL;
	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) && ret > 0)
	{
		buff[ret] = '\0';
		i = ft_strlen(tmp);
		if (!(tmp = ft_realloc(tmp, i, i + ret)))
			return (-1);
		tmp = ft_strcat(tmp, buff);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (tmp == NULL && ret < BUFF_SIZE)
		return (0);
	*line = ft_strcdup(tmp, '\n');
	if (ft_strchr(tmp, '\n'))
		tmp = ft_move(&tmp);
	else
		ft_strclr(&tmp);
	return (1);
}
