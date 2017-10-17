/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 05:22:30 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/17 05:30:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*local_rp(char *str, int i, char *old, char *new)
{
	char	*res;

	res = ft_strndup(str, i);
	res = ft_dstrjoin(res, new, 1);
	res = ft_dstrjoin(res, str + i + ft_strlen(old), 1);
	ft_strdel(&str);
	return (res);
}

char		*ft_replace(char *str, char *old, char *new)
{
	int	len;
	int	i;

	if (ft_strlen(new) == 0)
		return (str);
	len = ft_strlen(old);
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str + i, old, len))
		{
			str = local_rp(str, i, old, new);
			i += ft_strlen(new);
			continue ;
		}
		i++;
	}
	return (str);
}
