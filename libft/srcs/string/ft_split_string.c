/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:47:19 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/13 23:33:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*delimitor(char *s, char *c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_strncmp(s + i, c, ft_strlen(c)))
			break ;
		i += ft_strlen(c);
	}
	return (s + i);
}

static int	first_delimitor(char *s, char **m, char *c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, c, ft_strlen(c)))
			break ;
		i++;
	}
	*m = (s + i);
	return (i);
}

static int	get_la(char *s, char *c)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[0])
	{
		if (!(s = delimitor(s, c))[0])
			break ;
		first_delimitor(s, &tmp, c);
		s = tmp;
		i++;
	}
	return (i);
}

char		**ft_split_string(char const *s, char *c)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*t;

	if (!s || !(split = (char **)malloc(sizeof(char *) \
		* (get_la((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	t = (char*)s;
	while (t[0])
	{
		if (!(t = delimitor(t, c))[0])
			break ;
		split[i] = ft_strndup(t, first_delimitor(t, &tmp, c));
		t = tmp;
		i++;
	}
	split[i] = NULL;
	return (split);
}
