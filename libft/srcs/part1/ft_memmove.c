/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:39:43 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 04:34:05 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstm;
	const char	*srcm;

	dstm = dst;
	srcm = src;
	if (srcm < dstm)
	{
		dstm += len;
		srcm += len;
		while (len--)
			*--dstm = *--srcm;
	}
	else if (srcm != dstm)
	{
		while (len--)
			*dstm++ = *srcm++;
	}
	return (dst);
}
