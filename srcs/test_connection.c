/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 01:48:05 by jguyet            #+#    #+#             */
/*   Updated: 2017/06/06 01:48:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

t_protocol_information	*prepare_protocol_information(t_nmap *nmap, int port)
{
	t_protocol_information	*pi = new_protocol_information();

	if (pi == NULL)
		return (NULL);
	pi->pid = nmap->pid;
	pi->ttl = nmap->ttl;
	pi->sequence = nmap->sequence;
	pi->port = port;
	pi->protocol = nmap->protocol;
	pi->scans = nmap->scans;
	protocol_information_set_dest_ip(pi, nmap->dest_ip);
	protocol_information_set_source_ip(pi, nmap->source_ip);
	return (pi);
}

BOOLEAN					test_connection(t_nmap *nmap, int port)
{
	t_protocol_information	*pi;
	t_message				*message_send;
	t_message				*message_rcv;
	t_recvfrom				*rcv_from;

	if (!(pi = prepare_protocol_information(nmap, port)))
		return (false);
	if (!(message_send = new_message(nmap->sweepminsize)))
		return (false);
	message_send->serialize(message_send, pi);

	/*int len = ft_strlen("TEST");
	
	if (len > (message_send->packet_len - 1))
		len = (message_send->packet_len - 1);
	if (len > 0) {
		ft_memcpy(message_send->data + (message_send->len - message_send->packet_len) + 1, "TEST", len);
	}*/

	if (send_message(nmap, message_send, pi) == false)
		return (false);
	if ((rcv_from = handle_message(nmap, pi, message_send->len)) == NULL)
		return (false);
	message_rcv = rcv_from->message;

	printf("CONNECTION OK : %s -> %s\n", pi->source_ip, get_hostname_ipv4(&rcv_from->from.sin_addr));

	printf("   Packet < (%s) [", get_hostname_ipv4(&rcv_from->from.sin_addr));
	message_rcv->tostring(message_rcv);
	printf("]\n");

	destruct_message(message_send);
	destruct_message(message_rcv);
	destruct_protocol_information(pi);
	return (true);
}