/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:53:55 by jguyet            #+#    #+#             */
/*   Updated: 2016/01/12 17:49:49 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strtrim_end(char *s, int i, char *c)
{
	int nbr;
	int n;
	int t;

	nbr = 0;
	while (s && s[i])
	{
		n = -1;
		t = 0;
		while (c[++n])
		{
			if (s[i] == c[n])
			{
				nbr++;
				t = 1;
				break ;
			}
		}
		if (t == 0)
			break ;
		i--;
	}
	return (nbr);
}

static int		ft_strtrim_start(char *s, int i, char *c)
{
	int nbr;
	int n;
	int t;

	nbr = 0;
	while (s && s[i])
	{
		n = -1;
		t = 0;
		while (c[++n])
		{
			if (s[i] == c[n])
			{
				nbr++;
				t = 1;
				break ;
			}
		}
		if (t == 0)
			break ;
		i++;
	}
	return (nbr);
}

char			*ft_strtrim_string(char const *s, char const *c)
{
	char		*result;
	int			end;
	int			start;

	if (!s || !c)
		return (NULL);
	if (!*s || !*c)
		return (ft_strnew(1));
	start = ft_strtrim_start((char*)s, 0, (char*)c);
	end = ft_strtrim_end((char*)s, ft_strlen(s) - 1, (char*)c);
	result = ft_strsub((char*)s, start, (ft_strlen(s) - end));
	return (result);
}
