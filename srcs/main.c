/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:50:56 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 01:51:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

int	main(int argc, char **argv)
{
	t_nmap	*nmap;

	if ((int)getuid() < 0)
	{
		ft_fprintf(1, "ft_nmap: you do not have the necessary rights\n");
	}
	nmap = singleton_nmap();
	if (nmap == NULL)
		return (0);
	if (!load_flag_list(nmap))
		return (0);
	if (argc > 1)
	{
		if (!load_flags(nmap, argc, argv))
			return (0);
		if (!set_flags_values(nmap))
			return (false);
		if (nmap->dest_ip)
		{
			printf("ft_nmap to %s (%s), %d hops max, %d byte packets\n", nmap->shost, nmap->dest_ip, nmap->max_hop, nmap->sweepminsize);
			nmap->launch(nmap);
		}
		else
		{
			if (nmap->shost == NULL)
				nmap->shost = ft_strdup("");
			ft_fprintf(1, "ft_nmap: cannot resolve %s: Unknow host\n", nmap->shost);
		}
	}
	else
	{
		print_help(nmap);
	}
	destruct_nmap(nmap);
	return (0);
}
