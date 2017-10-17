/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 02:30:43 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 02:30:45 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN			initialize_socket_receiver_connection(t_nmap *nmap)
{
	nmap->sock = socket(PROT_INTERNET_IPV4, nmap->socket_type, nmap->protocol->proto_sock_recv);
	if (!socket_connection_is_estabilised(nmap->sock))
	{
		if (nmap->sock && nmap->socket_type == SOCK_RAW)
		{
			nmap->socket_type = SOCK_DGRAM;
			printf("(Restart on SOCK_DGRAM socket type)\n");
			return (initialize_socket_receiver_connection(nmap));
		}
		return (false);
	}
	if (!bind_socket_receiver(nmap))
		return (bind_error());
	if (!set_on_socket_protocol_options(nmap))
		return (set_socket_options_error());
	return (true);
}

BOOLEAN			bind_socket_receiver(t_nmap *nmap)
{
	struct sockaddr_in sock_addr; 

	ft_memset(&sock_addr, '0', sizeof(struct sockaddr_in));
	sock_addr.sin_family = PROT_INTERNET_IPV4;
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	sock_addr.sin_port = htons(nmap->port);
	if (bind(nmap->sock, (struct sockaddr*)&sock_addr,\
		sizeof(struct sockaddr)) < 0)
		return (false);
	return (true);
}

BOOLEAN			set_on_socket_protocol_options(t_nmap *nmap)
{
	int opt;
	int ttl;

	opt = 1;
	ttl = nmap->ttl;
	if (setsockopt(nmap->sock, 0, TCP_IP_PACKET_HEADER_SERVICE,\
		&ttl, sizeof(ttl)) != 0)
		return (false);
	if (nmap->use_ip_header)
	{
		if ((setsockopt(nmap->sock, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt))) != 0)
			return (false);
	}
	if (F_SOCK_DEBUG)
		if (setsockopt(nmap->sock, SOL_SOCKET, SO_DEBUG, (char*)&opt, sizeof(opt)) != 0)
			return (false);
	if (F_DONTROUTE)
		if (setsockopt(nmap->sock, SOL_SOCKET, SO_DONTROUTE, (char*)&opt, sizeof(opt)) != 0)
			return (false);
	return (true);
}

/*
** boolean socket_connection_is_estabilised(int fd);
** return boolean
** if < 0 return false and print error message
*/
BOOLEAN			socket_connection_is_estabilised(int fd)
{
	if (fd == EAFNOSUPPORT)
	{
		printf("Erreur : L'implémentation ne supporte pas la ");
		printf("famille d'adresses indiquée.\n");
		return (false);
	}
	if (fd == EPROTONOSUPPORT)
	{
		printf("Erreur : Le type de protocole, ou le protocole lui-même ");
		printf("n'est pas disponible dans ce domaine de communication.\n");
		return (false);
	}
	if (fd < 0)
	{
		printf("Erreur : Socket connection has failed.\n");
		return (false);
	}
	return (true);
}

BOOLEAN			bind_error(void)
{
	printf("Error : Socket address is busy\n");
	return (false);
}

BOOLEAN			set_socket_options_error(void)
{
	printf("Error : Socket options\n");
	return (false);
}
