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

t_nmap		*singleton_nmap(void)
{
	static t_nmap	*nmap = NULL;

	if (nmap != NULL)
		return (nmap);
	if (!(nmap = (t_nmap*)malloc(sizeof(t_nmap))))
		return (NULL);
	nmap->sequence = 0;
	nmap->shost = NULL;
	nmap->addr = NULL;
	nmap->port = 80;
	nmap->launch = process_nmaproute;
	nmap->received = 0;
	nmap->send = 0;
	nmap->timeout.tv_sec = 5;
	nmap->pid = (getpid() & 0xFFFF) | 0x8000;
	nmap->ttl = 1;
	nmap->mintime = 0;
	nmap->totaltime = 0;
	nmap->maxtime = 0;
	nmap->max_hop = 30;
	nmap->protocol = get_protocol(ICMP);
	nmap->socket_type = INTERNAL_SOCK_FLUX;
	nmap->retry = true;
	nmap->use_ip_header = false;
# ifdef __linux__
	nmap->use_ip_header = true;
#endif
	nmap->dest_ip = NULL;
	nmap->sweepminsize = nmap->protocol->len;
	if (nmap->use_ip_header)
		nmap->sweepminsize += IPHDR_SIZE;
	nmap->sweepmaxsize = nmap->sweepminsize;
	struct in_addr local;
	local.s_addr = INADDR_ANY;
	nmap->source_ip = ft_strdup(get_hostname_ipv4(&local));
	nmap->write_message = NULL;
	nmap->interval_number_connection = NB_DEFAULT_INTERVAL_CONNECTION;
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
	if (nmap->write_message != NULL)
		ft_strdel(&nmap->write_message);
	free(nmap->ip_tab);
	free(nmap);
}

BOOLEAN		process_loop(t_nmap *nmap)
{
	int		i = 0;

	while (i < nmap->interval_number_connection)
	{
		//Open socket connection
		initialize_socket_receiver_connection(nmap);
		initialize_socket_sender_connection(nmap);

		if (i == 0)
			ft_printf("%2d ", nmap->ttl);
		//protocol_information -->
		t_protocol_information *pi = new_protocol_information();
		
		pi->pid = nmap->pid;
		pi->ttl = nmap->ttl;
		pi->sequence = nmap->sequence;
		pi->port = nmap->port;
		pi->protocol = nmap->protocol;
		protocol_information_set_dest_ip(pi, nmap->dest_ip);
		protocol_information_set_source_ip(pi, nmap->source_ip);


		nmap->message = new_message(nmap->sweepminsize);
		nmap->message->serialize(nmap->message, pi, nmap->use_ip_header);

		if (F_WRITING && nmap->write_message != NULL)
		{
			int len = ft_strlen(nmap->write_message);

			if (len > (nmap->message->packet_len - 1))
				len = (nmap->message->packet_len - 1);
			if (len > 0) {
				ft_memcpy(nmap->message->data + (nmap->message->len - nmap->message->packet_len) + 1, nmap->write_message, len);
			}
		}

		send_message(nmap, nmap->message);
		if ((nmap->ip_tab[i] = handle_message(nmap, pi)) != NULL)
		{
			if (ft_strcmp(nmap->ip_tab[i], nmap->dest_ip) == 0)
				nmap->retry = false;
		}
		else
		{
			ft_printf(" *");
		}
		destruct_message(nmap->message);
		destruct_protocol_information(pi);
		nmap->sequence++;
		//close socket connection
		close(nmap->sock);
		close(nmap->sock_snd);
		i++;
	}
	ft_printf("\n");
	return (nmap->retry);
}

static void	print_nmaproute_stats(t_nmap *nmap)
{
	float	mintime = 0;
	float	mediumtime = 0;
	float	maxtime = 0;

	if (nmap->mintime != 0)
		mintime = (((float)nmap->mintime) / 1000);
	if (nmap->received != 0)
		mediumtime = (nmap->totaltime / nmap->received) == 0 ? 0 : (((float)(nmap->totaltime / nmap->received)) / 1000);
	if (nmap->maxtime != 0)
		maxtime = (((float)nmap->maxtime) / 1000);
	printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n", mintime, mediumtime, maxtime, maxtime - mintime);
}

void		on_nmaproute_finished(t_nmap *nmap)
{
	if (!F_TIME_INFO)
		return ;
	printf("----------------------------------------------------------\n");
	print_nmaproute_stats(nmap);
}

BOOLEAN		process_nmaproute(t_nmap *nmap)
{
	if (!load_ip_tab(nmap))
			return (false);
	while (nmap->ttl <= nmap->max_hop && nmap->retry)
	{
		reset_ip_tab(nmap);
		if (process_loop(nmap) == false) {
			free_ip_tab(nmap);
			on_nmaproute_finished(nmap);
			return (true);
		}
		free_ip_tab(nmap);
		nmap->ttl++;
	}
	return (true);
}
