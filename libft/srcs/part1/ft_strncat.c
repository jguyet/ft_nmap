/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:08:35 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/04 02:06:30 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*dest_tmp;
	const char	*src_tmp;
	size_t		i;

	dest_tmp = s1;
	src_tmp = s2;
	i = ft_strlen(s1);
	while (n)
	{
		if ((dest_tmp[i] = *src_tmp++) == 0)
			break ;
		i++;
		n--;
	}
	dest_tmp[i] = '\0';
	return (s1);
}
