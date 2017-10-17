/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:00:34 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/19 05:00:36 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		ft_strdel(&array[i]);
	free(array);
}
