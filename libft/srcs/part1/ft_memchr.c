/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:13:41 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/04 00:04:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;
	unsigned char cc;

	tmp = (unsigned char*)s;
	cc = (unsigned char)c;
	if (!n || tmp == NULL)
		return (NULL);
	while (tmp && n)
	{
		if (*tmp == cc)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
