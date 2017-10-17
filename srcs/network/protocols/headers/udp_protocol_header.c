/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udp_protocol_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:10:16 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/19 00:10:17 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

#include <sys/time.h>

void		prepare_udp_header(t_message *message, t_protocol_information *pi)
{
	message->udp_header.source = htons(pi->pid);
	message->udp_header.dest = htons(pi->port);
	message->udp_header.len = htons((u_short)message->len - sizeof(struct iphdr));
	message->udp_header.check = 0;
	message->udp_header.seq = pi->sequence;
	message->udp_header.ttl = pi->ttl;
	gettimeofday((struct timeval*)&message->udp_header.tv, 0);
}

void		serialize_udp_header(t_message *message, t_protocol_information *pi, size_t iphdr_size)
{
	ft_memcpy(message->data + iphdr_size, &message->udp_header, pi->protocol->len);
	message->udp_header.check = 0;
	ft_memcpy(message->data + iphdr_size, &message->udp_header, pi->protocol->len);
}

void		deserialize_udp_header(t_message *message, t_protocol_information *pi)
{
	ft_memcpy(&message->udp_header, message->data, pi->protocol->len);
	message->data = message->data + pi->protocol->len;
}
