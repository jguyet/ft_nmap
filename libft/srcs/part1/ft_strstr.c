/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:53:03 by jguyet            #+#    #+#             */
/*   Updated: 2015/11/25 15:53:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int boolean;
	int s2_size;

	boolean = 0;
	s2_size = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (*s1 && *s2)
	{
		if (*s1 == *s2 && *s2++)
			boolean++;
		else if (boolean && (*s1 != *s2))
		{
			while (boolean != 0 && *s2--)
			{
				boolean--;
				s1--;
			}
		}
		if (boolean == s2_size)
			return ((char *)s1 - s2_size + 1);
		s1++;
	}
	return (NULL);
}
