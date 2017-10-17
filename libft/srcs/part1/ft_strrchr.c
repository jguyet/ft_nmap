/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:22:04 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/01 22:05:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp;
	unsigned char	*index;

	tmp = (unsigned char*)s;
	index = NULL;
	while (*tmp)
	{
		if (*tmp == (char)c)
			index = tmp;
		tmp++;
	}
	if (*tmp == (char)c)
		index = tmp;
	if (index != NULL)
		return ((char*)index);
	else
		return (NULL);
}
