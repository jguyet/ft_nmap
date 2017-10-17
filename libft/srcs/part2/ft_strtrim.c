/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:53:55 by jguyet            #+#    #+#             */
/*   Updated: 2016/01/12 17:49:49 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strchrnoprint2(char *s, int i)
{
	int nbr;

	nbr = 0;
	while (s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			nbr++;
		else
			break ;
		i--;
	}
	return (nbr);
}

char			*ft_strtrim(char const *s)
{
	char		*result;
	int			end;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (ft_strnew(1));
	end = ft_strchrnoprint2((char*)s, ft_strlen(s) - 1);
	result = ft_strsub((char*)s, 0, (ft_strlen(s) - end));
	return (result);
}
