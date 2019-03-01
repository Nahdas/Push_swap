/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:19:20 by ayguillo          #+#    #+#             */
/*   Updated: 2019/03/01 11:51:23 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
