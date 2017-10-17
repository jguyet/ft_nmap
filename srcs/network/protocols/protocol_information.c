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

t_protocol_information	*new_protocol_information(void)
{
	t_protocol_information	*p;

	if (!(p = (t_protocol_information*)malloc(sizeof(t_protocol_information))))
		return (NULL);
	ft_memset(p, 0, sizeof(t_protocol_information));
	return (p);
}

void					destruct_protocol_information(t_protocol_information *p)
{
	ft_strdel(&p->source_ip);
	ft_strdel(&p->dest_ip);
	free(p);
}

void					protocol_information_set_dest_ip(t_protocol_information *p, char *ip)
{
	p->dest_ip = ft_strdup(ip);
}

void					protocol_information_set_source_ip(t_protocol_information *p, char *ip)
{
	p->source_ip = ft_strdup(ip);
}