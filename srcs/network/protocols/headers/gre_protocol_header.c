/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gre_protocol_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:10:00 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/19 00:10:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void		prepare_gre_header(t_message *message, t_protocol_information *pi)
{
	message->gre_header.flags = htons(0x2001);
	message->gre_header.proto = htons(pi->port);
	message->gre_header.length = 0;
	message->gre_header.callid = htons(pi->pid + pi->sequence);
}

void		serialize_gre_header(t_message *message, t_protocol_information *pi)
{
	ft_memcpy(message->data + IPHDR_SIZE, &message->gre_header, pi->protocol->len);
	ft_memset(message->data + IPHDR_SIZE + pi->protocol->len, '0', message->packet_len);
}

void		deserialize_gre_header(t_message *message, t_protocol_information *pi)
{
	ft_memcpy(&message->gre_header, message->data, pi->protocol->len);
	message->data = message->data + pi->protocol->len;
}
