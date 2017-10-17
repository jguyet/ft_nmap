/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:49:41 by jguyet            #+#    #+#             */
/*   Updated: 2015/11/27 00:49:43 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	i = 0;
	if (start == 0 && len == 0)
		return (ft_strnew(1));
	if (s && len && (result = (char*)malloc(sizeof(char)
	* (len + 1))))
	{
		while (s[start] && len)
		{
			result[i] = s[start];
			start++;
			i++;
			len--;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
