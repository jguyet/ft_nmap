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

/*
static BOOLEAN		print_error_args_string(char *error, char *args)
{
	ft_fprintf(1, error, args);
	return (false);
}*/

/*
static BOOLEAN		print_error_two_args(char *error, int arg, int arg2)
{
	ft_fprintf(1, error, arg, arg2);
	return (false);
}*/

BOOLEAN				set_flags_values(t_nmap *nmap)
{
	if (F_PORT->actif)
	{
		nmap->ports = load_ports_flags(F_PORT->value);
		if (nmap->ports == NULL)
			return (print_error_args(F_PORT->error, nmap->port));
	}
	if (F_SPEEDUP->actif)
	{
		nmap->speedup = ft_atoi(F_SPEEDUP->value);
		if (nmap->speedup < 1 || nmap->speedup > 250)
			return (print_error_args(F_SPEEDUP->error, nmap->speedup));
	}
	if (F_SCAN->actif)
	{
		load_flag_scan(nmap->scans, F_SCAN->value);
	}
	if (nmap->ports == NULL)
		return (print_error("Add cibled ports : (ex: --ports 80-100)"));
	return (true);
}
