/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_protocol_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:10:08 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/19 00:10:10 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void		prepare_iphdr(t_message *message, t_protocol_information *pi)
{
	//message->ip_header.src.s_addr = INADDR_ANY;

	/*if (!(inet_pton(AF_INET, nmap->destip, &message->ip_header.dest)))
	{
		printf("ft_nmap: Can't set destination network address\n");
		exit(EXIT_FAILURE);
	}*/

	message->ip_header.ttl = pi->ttl;
	message->ip_header.protocol = pi->protocol->proto;
	message->ip_header.version = 4;//ipv4
	message->ip_header.hl = sizeof(struct iphdr) >> 2;
	message->ip_header.pid = htons(pi->pid);
	message->ip_header.service = 0;
	message->ip_header.off = 0;
	message->ip_header.len = 0;
	message->ip_header.checksum = 0;
	message->ip_header.checksum = 0;

	char *tmp_src = ft_strdup(pi->source_ip);
	char *tmp_dest = ft_strdup(pi->dest_ip);

	message->ip_header.src = get_sockaddr_in_ipv4(tmp_src)->sin_addr;
	message->ip_header.dest = get_sockaddr_in_ipv4(tmp_dest)->sin_addr;

	ft_strdel(&tmp_src);
	ft_strdel(&tmp_dest);
}

void		serialize_ip_header(t_message *message, t_protocol_information *pi)
{
	message->ip_header.len = IPHDR_SIZE + pi->protocol->len + message->packet_len;
	ft_memcpy(message->data, &message->ip_header, IPHDR_SIZE);
	message->ip_header.checksum = checksum(&message->data, message->ip_header.len);
}
