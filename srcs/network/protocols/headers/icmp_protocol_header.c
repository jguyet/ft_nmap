/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp_protocol_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:10:22 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/19 00:10:24 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void		prepare_icmp_header(t_message *message, t_protocol_information *pi)
{
	message->icmp_header.type = ICMP_ECHO;
	message->icmp_header.un.echo.id = htons(pi->pid);
	message->icmp_header.un.echo.sequence = htons(pi->sequence);
	message->icmp_header.checksum = 0;
}

void		serialize_icmp_header(t_message *message, t_protocol_information *pi, size_t iphdr_size)
{
	ft_memcpy(message->data + iphdr_size, &message->icmp_header, pi->protocol->len);
	ft_memset(message->data + iphdr_size + pi->protocol->len, '0', message->packet_len);
	message->icmp_header.checksum = checksum(message->data + iphdr_size, pi->protocol->len + message->packet_len);
	ft_memcpy(message->data + iphdr_size, &message->icmp_header, pi->protocol->len);
}

void		deserialize_icmp_header(t_message *message, t_protocol_information *pi)
{
	ft_memcpy(&message->icmp_header, message->data, pi->protocol->len);
	message->data = message->data + pi->protocol->len;
}
