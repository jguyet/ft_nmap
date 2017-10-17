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

t_message		*deserialize_packet(t_protocol_information *pi, void *packet, int ret)
{
	t_message *message;
	void		*packet_copy;


	if (!(packet_copy = ft_strnew(ret)))
		return (NULL);
	ft_memcpy(packet_copy, packet, ret);
	if (!(message = deserialize_message(pi, packet_copy, ret)))
		return (NULL);
	return (message);
}

/*
** read le message icmp header-packet
*/
t_recvfrom		*handle_message(t_nmap *nmap, t_protocol_information *pi, int packet_size)
{
	t_recvfrom	*rcvfrom;
	int			ret;
	char		packet[nmap->sweepminsize];
	socklen_t	fromlen;

	if (!(rcvfrom = (t_recvfrom*)malloc(sizeof(t_recvfrom))))
		return (NULL);
	fromlen = sizeof(rcvfrom->from);
	if ((ret = recvfrom(nmap->sock, &packet, packet_size, 0, (struct sockaddr*)&rcvfrom->from, &fromlen)) != -1)
	{
		if (!(rcvfrom->message = deserialize_packet(pi, packet, ret)))
		{
			free(rcvfrom);
			return (NULL);
		}
		return (rcvfrom);
	}
	free(rcvfrom);
	return (NULL);
}
