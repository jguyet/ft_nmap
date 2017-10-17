/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_sender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 02:30:43 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 02:30:45 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN			initialize_socket_sender_connection(t_nmap *nmap)
{
	nmap->sock_snd = socket(PROT_INTERNET_IPV4, nmap->socket_type, nmap->protocol->proto);
	if (!socket_connection_is_estabilised(nmap->sock_snd))
	{
		if (nmap->sock_snd && nmap->socket_type == SOCK_RAW)
		{
			nmap->socket_type = SOCK_DGRAM;
			printf("(Restart on SOCK_DGRAM socket type)\n");
			return (initialize_socket_sender_connection(nmap));
		}
		return (false);
	}
	//if (!bind_socket_sender(nmap))
	//	return (bind_error());
	if (!set_on_socket_sender_options(nmap))
		return (set_socket_options_error());
	return (true);
}

BOOLEAN			bind_socket_sender(t_nmap *nmap)
{
	struct sockaddr_in sock_addr; 

	ft_memset(&sock_addr, '0', sizeof(struct sockaddr_in));
	sock_addr.sin_family = PROT_INTERNET_IPV4;
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	sock_addr.sin_port = htons(nmap->port);
	if (bind(nmap->sock_snd, (struct sockaddr*)&sock_addr,\
		sizeof(struct sockaddr)) < 0)
		return (false);
	return (true);
}

BOOLEAN			set_on_socket_sender_options(t_nmap *nmap)
{
	int opt;
	int ttl;

	opt = 1;
	ttl = nmap->ttl;
	if (setsockopt(nmap->sock_snd, 0, TCP_IP_PACKET_HEADER_SERVICE,\
		&ttl, sizeof(ttl)) != 0)
		return (false);
	if (nmap->use_ip_header)
	{
		if ((setsockopt(nmap->sock_snd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt))) != 0)
			return (false);
	}
	if (setsockopt(nmap->sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&nmap->timeout, sizeof(nmap->timeout)) != 0)
		return (false);
	return (true);
}

BOOLEAN		send_message(t_nmap *nmap, t_message *message)
{
	int		res;

	nmap->send++;
	nmap->start_time = get_current_time_millis();
	if (F_ASCII_DEBUG_MSG)
	{
		printf("\n   Packet > (%s) [", nmap->dest_ip);
		message->tostring(message);
		printf("]\n");
	}
	res = sendto(nmap->sock, message->data, message->len, MSG_DONTWAIT, (struct sockaddr*)nmap->addr, sizeof(*nmap->addr));
	
	if (res < 0)
	{
		ft_fprintf(1, "ft_nmaproute: sendto: Network is unreachable\n");
		return (false);
	}
	if (res != message->len)
	{
		ft_printf("ft_nmaproute: wrote %s %d chars, ret=%d\n", nmap->shost, message->len, res);
		return (false);
	}
	return (true);
}
