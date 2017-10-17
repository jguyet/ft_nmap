/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protocol_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 04:19:25 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 04:19:27 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

t_message	*new_message(size_t size)
{
	t_message	*message;

	if (!(message = (t_message*)malloc(sizeof(t_message))))
		return (NULL);
	ft_bzero(message, sizeof(t_message));
	message->len = size;
	message->serialize = serialize_message;
	message->tostring = tostring;
	if (!(message->data = ft_strnew(message->len)))
		return (NULL);
	return (message);
}

BOOLEAN		serialize_message(t_message *message, t_protocol_information *pi)
{
	//prepare ip header
	prepare_iphdr(message, pi);

	//set message total length
	message->packet_len = message->len - (pi->protocol->len + IPHDR_SIZE);
	//prepare protocol header
	pi->protocol->prepare_header(message, pi);
	//serialize message
	pi->protocol->serialize(message, pi);
	serialize_ip_header(message, pi);
	return (true);
}

t_message		*deserialize_message(t_protocol_information *pi, void *ptr, int ptr_size)
{
	t_message *message;

	if (!(message = new_message(0)))
		return (NULL);
	message->data = ptr;
	message->packet_len = ptr_size;

	ft_memcpy(&message->ip_header, message->data, IPHDR_SIZE);
	message->data += IPHDR_SIZE;
	message->packet_len -= IPHDR_SIZE;

	pi->protocol->deserialize(message, pi);
	message->packet_len -= pi->protocol->len;
	message->len = ptr_size;
	message->data = ptr;
	return (message);
}

void			destruct_message(t_message *message)
{
	if (message->data != NULL)
		free(message->data);
	free(message);
}

void			tostring(t_message *message)
{
	int 	i = 0;
	char	msg[message->len + 1];

	while (i < message->len)
	{
		char *m = (char*)message->data;

		if (ft_isprint(m[i]))
			msg[i] = m[i];
		else
			msg[i] = '.';
		i++;
	}
	msg[i] = 0;
	printf("%s (len: %d)", msg, message->len);
}
