/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:09:13 by jguyet            #+#    #+#             */
/*   Updated: 2015/11/25 16:09:26 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t lim;

	if (!*s2)
		return ((char*)s1);
	lim = ft_strlen(s2);
	if (lim == 0)
		return ((char*)s1);
	while (n && *s1 && *s1 != *s2)
	{
		s1++;
		n--;
	}
	while (n && *s1)
	{
		if (n >= lim)
			if (!ft_strncmp(s1, s2, lim))
				return ((char*)s1);
		s1++;
		n--;
	}
	if (!*s1 || !n)
		return (NULL);
	return ((char*)s1);
}
