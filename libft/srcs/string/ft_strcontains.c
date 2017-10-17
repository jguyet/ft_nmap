/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:40:45 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/08 19:40:47 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOLEAN	ft_strcontains(char const *src, char const *srh)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (ft_strcmp(src + i, srh) == 0)
			return (true);
		i++;
	}
	return (false);
}
