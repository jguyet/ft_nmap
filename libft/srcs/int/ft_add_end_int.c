/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:50:29 by jguyet            #+#    #+#             */
/*   Updated: 2016/01/12 19:45:00 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			*ft_add_end_int(int *tab, int val, int size)
{
	int *new;
	int i;

	i = 0;
	if (size == 0)
	{
		tab[0] = val;
		return (tab);
	}
	if (!(new = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = val;
	free(tab);
	return (new);
}
