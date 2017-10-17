/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:06:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 08:06:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

static BOOLEAN		print_error(char *error)
{
	ft_fprintf(1, "ft_nmap: %s\n", error);
	return (false);
}


static BOOLEAN		print_error_args(char *error, int args)
{
	ft_fprintf(1, error, args);
	return (false);
}

static BOOLEAN		print_error_args_string(char *error, char *args)
{
	ft_fprintf(1, error, args);
	return (false);
}

static BOOLEAN		print_error_two_args(char *error, int arg, int arg2)
{
	ft_fprintf(1, error, arg, arg2);
	return (false);
}

BOOLEAN				set_flags_values(t_nmap *nmap)
{
	if (F_MAXHOPS)//"max-ttl"
		nmap->max_hop = ft_atoi(nmap->flags[0]->value);
	if (nmap->max_hop > 255 || nmap->max_hop < 0)
		return (print_error(nmap->flags[0]->error));
	if (F_FIRSTHOPS)
		nmap->ttl = ft_atoi(nmap->flags[1]->value);
	if (nmap->ttl > nmap->max_hop || nmap->ttl < 0)
		return (print_error_two_args(nmap->flags[1]->error, nmap->ttl, nmap->max_hop));
	if (nmap->ttl <= 0)
		return (print_error("ft_nmaproute: first ttl must be > 0"));
	if (F_PROTOCOL)
	{
		nmap->sweepminsize -= nmap->protocol->len;
		if (nmap->use_ip_header)
			nmap->sweepminsize -= IPHDR_SIZE;
		nmap->protocol = get_protocol_by_name(nmap->flags[5]->value);
		if (nmap->protocol == NULL)
			return (print_error_args_string(nmap->flags[5]->error, nmap->flags[5]->value));
		nmap->sweepminsize = nmap->protocol->len + nmap->sweepminsize;
		if (nmap->use_ip_header)
			nmap->sweepminsize += IPHDR_SIZE;
		nmap->sweepmaxsize = nmap->sweepminsize;
	}
	if (F_PORT)
		nmap->port = ft_atoi(nmap->flags[6]->value);
	if (nmap->port < 1 || nmap->port > 32768)
		return (print_error_args(nmap->flags[6]->error, nmap->port));
	if (F_IP_HDR && ft_strcmp(nmap->flags[8]->value, "true") == 0)
	{
		if (!nmap->use_ip_header)
			nmap->sweepminsize += IPHDR_SIZE;
		nmap->use_ip_header = true;
	}
	else if (F_IP_HDR && ft_strcmp(nmap->flags[8]->value, "false") == 0)
	{
		if (nmap->use_ip_header)
			nmap->sweepminsize -= IPHDR_SIZE;
		nmap->use_ip_header = false;
	}
	if (F_WRITING)
		nmap->write_message = nmap->flags[11]->value;
	if (F_INTERVAL_CONNECTION)
		nmap->interval_number_connection = ft_atoi(nmap->flags[12]->value);
	if (nmap->interval_number_connection > 255)
		return (print_error(nmap->flags[12]->error));
	return (true);
}
