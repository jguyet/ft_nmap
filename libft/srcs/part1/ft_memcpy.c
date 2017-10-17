/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:51:39 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 03:25:22 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp1;
	const char	*tmp2;
	size_t		i;

	tmp1 = dst;
	tmp2 = src;
	i = 0;
	while (i < n)
	{
		*tmp1++ = *tmp2++;
		i++;
	}
	return (dst);
}
