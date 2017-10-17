/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:50:50 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 02:17:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *tmp1;
	const unsigned char *tmp2;
	size_t				i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	if (tmp1 == NULL || tmp2 == NULL)
		return (0);
	while (i < n)
	{
		if (tmp1[i] != tmp2[i] && (tmp1[i] || tmp2[i]))
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
