/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 05:17:08 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/02 05:17:10 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_uitoabase(unsigned long long int nbr, char *base)
{
	char					*res;
	int						size;
	unsigned long long int	len;
	unsigned long long int	tmp;

	tmp = nbr;
	len = 1;
	size = 0;
	while ((tmp = tmp / ft_strlen(base)))
	{
		len = len * ft_strlen(base);
		size++;
	}
	tmp = nbr;
	res = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (len)
	{
		res[size] = base[(tmp / len)];
		tmp = tmp - ((tmp / len) * len);
		len = len / ft_strlen(base);
		size++;
	}
	res[size] = '\0';
	return (res);
}
