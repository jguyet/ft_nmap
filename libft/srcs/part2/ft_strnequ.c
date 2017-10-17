/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:33:21 by jguyet            #+#    #+#             */
/*   Updated: 2015/11/27 00:33:23 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = (int)n;
	if (s1 && s2 && n)
	{
		while (s1[i] && n && s2[i] && (s1[i] == s2[i]))
		{
			n--;
			i++;
		}
		if ((i == len) || ((i >= ft_strlen(s1))
			&& (i >= ft_strlen(s2))))
			return (1);
	}
	else if ((s1 || s2) && !n)
		return (1);
	return (0);
}
