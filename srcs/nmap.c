/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 01:48:05 by jguyet            #+#    #+#             */
/*   Updated: 2017/06/06 01:48:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN		init_scans(t_nmap *nmap)
{
	if (!(nmap->scans = malloc(sizeof(t_scan))))
		return (false);
	nmap->scans->syn = false;
	nmap->scans->null = false;
	nmap->scans->fin = false;
	nmap->scans->xmas = false;
	nmap->scans->ack = false;
	nmap->scans->udp = false;
	return (true);
}

t_nmap		*singleton_nmap(void)
{
	static t_nmap	*nmap = NULL;

	if (nmap != NULL)
		return (nmap);
	if (!(nmap = (t_nmap*)malloc(sizeof(t_nmap))))
		return (NULL);
	nmap->sequence = 0;
	nmap->port = 80;
	nmap->ports = NULL;
	nmap->speedup = 1;
	nmap->shost = NULL;
	nmap->timeout.tv_sec = 5;
	nmap->launch = process_nmaproute;
	nmap->pid = (getpid() & 0xFFFF) | 0x8000;
	nmap->ttl = 64;
	nmap->protocol = get_protocol(TCP);
	nmap->socket_type = INTERNAL_SOCK_FLUX;
	nmap->dest_ip = NULL;
	nmap->sweepminsize = nmap->protocol->len + IPHDR_SIZE;
	struct in_addr local;
	local.s_addr = INADDR_ANY;
	nmap->source_ip = ft_strdup(get_hostname_ipv4(&local));
	if (init_scans(nmap) == false)
		return (NULL);
	return (nmap);
}

void		destruct_nmap(t_nmap *nmap)
{
	int i = 0;

	while (i < FLAGS_SIZE)
	{
		ft_strdel(&nmap->flags[i]->name);
		ft_strdel(&nmap->flags[i]->error);
		ft_strdel(&nmap->flags[i]->help);
		free(nmap->flags[i]);
		i++;
	}
	free(nmap->flags);
	if (nmap->addr != NULL)
		free(nmap->addr);
	if (nmap->shost != NULL)
		ft_strdel(&nmap->shost);
	if (nmap->source_ip != NULL)
		ft_strdel(&nmap->source_ip);
	if (nmap->dest_ip != NULL)
		ft_strdel(&nmap->dest_ip);
	free(nmap);
}

char		*get_string_scans(t_scan *scans)
{
	char *scan;

	scan = NULL;///SYN/NULL/FIN/XMAS/ACK/UDP
	if (scans->syn)
		scan = ft_dstrjoin(scan, "SYN", 1);
	if (scans->null)
	{
		if (scan != NULL)
			scan = ft_dstrjoin(scan, "/", 1);
		scan = ft_dstrjoin(scan, "NULL", 1);
	}
	if (scans->fin)
	{
		if (scan != NULL)
			scan = ft_dstrjoin(scan, "/", 1);
		scan = ft_dstrjoin(scan, "FIN", 1);
	}
	if (scans->xmas)
	{
		if (scan != NULL)
			scan = ft_dstrjoin(scan, "/", 1);
		scan = ft_dstrjoin(scan, "XMAS", 1);
	}
	if (scans->ack)
	{
		if (scan != NULL)
			scan = ft_dstrjoin(scan, "/", 1);
		scan = ft_dstrjoin(scan, "ACK", 1);
	}
	if (scans->udp)
	{
		if (scan != NULL)
			scan = ft_dstrjoin(scan, "/", 1);
		scan = ft_dstrjoin(scan, "UDP", 1);
	}
	return (scan);
}

BOOLEAN		process_nmaproute(t_nmap *nmap)
{
	printf("Scan Configurations\n");
	printf("Target Ip-Address : %s\n", nmap->dest_ip);
	printf("No of Ports to scan : %d\n", tab_length(nmap->ports));
	printf("Scans to be performed : %s\n", get_string_scans(nmap->scans));
	printf("No of threads : %d\n", nmap->speedup);
	printf("Scanning..\n");

	//int i = 0;

	//Open socket connection
	initialize_socket_receiver_connection(nmap);
	initialize_socket_sender_connection(nmap);

	test_connection(nmap, 80);
	/*while (i < nmap->speedup)
	{
		new_thread(nmap);
		i++;
	}*/
	//process_test(nmap, 80);
	sleep(3000);

	//close socket connection
	close(nmap->sock);
	close(nmap->sock_snd);
	return (true);
}
