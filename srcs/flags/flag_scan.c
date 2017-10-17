/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:06:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 08:06:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void        load_flag_scan(t_scan *scans, char *value)
{
	char    **split;
	int     i;

	if (!(split = ft_split_string(value, "/")))
		return ;
	i = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], "SYN") == 0)
			scans->syn = true;
		else if (ft_strcmp(split[i], "NULL") == 0)
			scans->null = true;
		else if (ft_strcmp(split[i], "NULL") == 0)
			scans->null = true;
		else if (ft_strcmp(split[i], "FIN") == 0)
			scans->fin = true;
		else if (ft_strcmp(split[i], "XMAS") == 0)
			scans->xmas = true;
		else if (ft_strcmp(split[i], "ACK") == 0)
			scans->ack = true;
		else if (ft_strcmp(split[i], "UDP") == 0)
			scans->udp = true;
		i++;
	}
	free_array(split);
}