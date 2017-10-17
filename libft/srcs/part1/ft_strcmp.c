/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:48:34 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 01:59:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int res;

	if ((s1 == NULL && s2 == NULL)
		|| (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
		return (0);
	if (s1 == NULL || ft_strlen(s1) == 0)
		return (0 - *(unsigned char *)s2);
	if (s2 == NULL || ft_strlen(s2) == 0)
		return (*(unsigned char *)s1 - 0);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	res = *(unsigned char *)s1 - *(unsigned char *)s2;
	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? res : res);
}
