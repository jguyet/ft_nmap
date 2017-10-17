/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 04:21:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/19 04:25:42 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sleep(int millis)
{
	long long int	i;
	int				retry;

	retry = 0;
	while (1)
	{
		i = 0;
		retry++;
		while (i < (TIME_MILLIS * millis))
		{
			i++;
		}
		if (retry == 1)
			break ;
	}
}
