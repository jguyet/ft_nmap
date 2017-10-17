/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:59:58 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/05 01:44:04 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1_tmp;
	unsigned char	*str2_tmp;
	size_t			i;

	if (!n)
		return (NULL);
	i = 0;
	str1_tmp = (unsigned char*)dst;
	str2_tmp = (unsigned char*)src;
	while (i < n)
	{
		str1_tmp[i] = str2_tmp[i];
		if (str1_tmp[i] == (unsigned char)c)
			return (&str1_tmp[i + 1]);
		i++;
	}
	return (NULL);
}
