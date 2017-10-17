/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 04:05:28 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/02 04:45:23 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*delim(char *src, char c)
{
	while (*src == c)
	{
		src++;
	}
	return (src);
}

static int	occus(char *src, char c)
{
	int occus;

	occus = 0;
	while (*src && *src != c)
	{
		src++;
		occus++;
	}
	return (occus);
}

static char	*nextoccus(char *src, char c)
{
	while (*src && *src != c)
	{
		src++;
	}
	return (src);
}

t_list		*ft_lstsplit(char const *src, char c)
{
	t_list	*result;
	t_list	*start;
	int		first;

	if (!src)
		return (NULL);
	first = 1;
	while (*src)
	{
		if (!*(src = delim((char*)src, c)))
			break ;
		result = ft_lstnew(ft_strndup(src, occus((char*)src, c) + 1),
			occus((char*)src, c));
		if (first == 1)
		{
			start = result;
		}
		else
			ft_lstadd(&start, result);
		src = nextoccus((char*)src, c);
		first = 0;
	}
	return (start);
}
