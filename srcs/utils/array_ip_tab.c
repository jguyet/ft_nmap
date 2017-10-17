/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ip_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 01:08:43 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/19 01:08:46 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN				ip_tab_contains(t_nmap *nmap, struct in_addr *addr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < nmap->interval_number_connection)
	{
		tmp = get_hostname_ipv4(addr);
		if (nmap->ip_tab[i] != NULL && tmp != NULL && ft_strcmp(nmap->ip_tab[i], tmp) == 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

void		reset_ip_tab(t_nmap *nmap)
{
	int i;

	i = 0;
	while (i < nmap->interval_number_connection)
	{
		nmap->ip_tab[i++] = NULL;
	}
}

void		free_ip_tab(t_nmap *nmap)
{
	int i;

	i = 0;
	while (i < nmap->interval_number_connection)
	{
		if (nmap->ip_tab[i] != NULL)
		{
			ft_strdel(&nmap->ip_tab[i]);
		}
		i++;
	}
}

BOOLEAN		load_ip_tab(t_nmap *nmap)
{
	if (!(nmap->ip_tab = (char **)malloc(\
        sizeof(char *) * nmap->interval_number_connection)))
		return (false);
    return (true);
}
