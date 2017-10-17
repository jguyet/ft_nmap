/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:09:41 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 05:09:42 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN				check_packet(t_nmap *nmap, t_protocol_information *pi, void *packet, int ret, BOOLEAN use_ip_hdr)
{
	t_message *message;

	if (!(message = deserialize_message(pi, packet, ret, use_ip_hdr)))
		return (true);
	if (F_ASCII_DEBUG_MSG)
	{
		printf("   Packet < (%s) [", pi->dest_ip);
		message->tostring(message);
		printf("]\n");
	}
	free(message);
	return (true);
}

/*
** read le message icmp header-packet
*/
char		*handle_message(t_nmap *nmap, t_protocol_information *pi)
{
	int	ret;
	char packet[nmap->sweepminsize];
	struct sockaddr_in from;
	socklen_t fromlen = sizeof(from);
	
	if ((ret = recvfrom(nmap->sock, &packet, nmap->message->len, 0, (struct sockaddr*)&from, &fromlen)) != -1)
	{
		if (!check_packet(nmap, pi, packet, ret, nmap->use_ip_header))
			return (handle_message(nmap, pi));
		return (process_received_message(nmap, &from));
	}
	return (NULL);
}

char		*process_received_message(t_nmap *nmap, struct sockaddr_in *addr)
{
	float			time_of;
	char			*ip_addr;
	BOOLEAN			printhost;
	char			*ndd;
	float			n_response_time;
	char			*response_time;

	if (!(ip_addr = ft_strdup(get_hostname_ipv4(&addr->sin_addr))))
		return (NULL);
	time_of = (get_current_time_millis() - nmap->start_time);
	printhost = ip_tab_contains(nmap, &addr->sin_addr);

	if (printhost == false || F_ASCII_DEBUG_MSG || F_INTERVAL_CONNECTION)
	{
		if (nmap->ip_tab[0] != NULL && !F_ASCII_DEBUG_MSG)
			ft_printf("\n   ");
		if (F_ASCII_DEBUG_MSG)
			ft_printf("  ");
		if (!(ndd = get_hostname_by_in_addr(&addr->sin_addr)))
			return (NULL);
		if (!F_PRINT_HOP_ADDR)
		{
			ft_putstr(" ");
			ft_putstr(ndd);
			ft_printf(" (%s)", ip_addr);
		}
		else
			ft_printf(" %s ", ip_addr);
		ft_strdel(&ndd);
	}
	n_response_time = (time_of / (float)1000);
	if (n_response_time < 0)
		n_response_time = 0;
	if (!(response_time = ft_convert_double_to_string(n_response_time, 3)))
		return (NULL);
	ft_printf(" %s ms ", response_time);
	ft_strdel(&response_time);
	nmap->totaltime += time_of;
	if (nmap->mintime == 0 || nmap->mintime > time_of)
		nmap->mintime = time_of;
	if (nmap->maxtime == 0 || nmap->maxtime < time_of)
		nmap->maxtime = time_of;
	nmap->received++;
	return (ip_addr);
}
