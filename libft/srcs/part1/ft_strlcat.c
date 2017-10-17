/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:04:51 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/01 22:06:17 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		dlen;
	char		*dst_cpy;
	const char	*src_cpy;

	n = size;
	src_cpy = src;
	dst_cpy = dst;
	while (*dst_cpy != '\0' && n--)
		dst_cpy++;
	dlen = dst_cpy - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*src_cpy != '\0')
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dlen + (src_cpy - src));
}
