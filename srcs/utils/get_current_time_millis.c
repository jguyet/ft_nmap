/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time_millis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:26:44 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 05:26:46 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

/*
** retourne le temps actuel en millisecondes
*/
long		get_current_time_millis()
{
	struct timeval time_v;

	if (gettimeofday(&time_v, 0) == -1)
		return (0);
	return (time_v.tv_usec);
}
