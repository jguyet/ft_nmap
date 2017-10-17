/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 21:26:39 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/24 21:26:41 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

BOOLEAN			has_help(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-help") == 0)
			return (true);
		if (ft_strcmp(argv[i], "--help") == 0)
			return (true);
		i++;
	}
	return (false);
}

BOOLEAN			print_help(t_nmap *nmap)
{
	int		i;

	printf("usage: ft_nmap :\n");
	i = 0;
	while (i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->special == true)
			printf(" %s", nmap->flags[i]->help);
		i++;
	}
	printf(" --help     Print this help screen\n");
	return (false);
}

BOOLEAN			activ_flags(t_nmap *nmap, char *arg)
{
	int		i;

	i = -1;
	while (++i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->special == true)
			continue ;
		if (ft_strncmp(nmap->flags[i]->name, arg,\
			ft_strlen(nmap->flags[i]->name)) == 0)
		{
			nmap->flags[i]->actif = true;
			break ;
		}
	}
	return (true);
}

BOOLEAN			select_value_special_flags(t_nmap *nmap,\
	int currentid, char *arg, char **argv, int argc)
{
	int		i;

	i = 0;
	while (i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->type == -1\
			|| nmap->flags[i]->special == false\
			|| ft_strcmp(nmap->flags[i]->name, arg) != 0)
		{
			i++;
			continue ;
		}
		if ((currentid + 1) >= argc) {
			print_help(nmap);
			exit(0);
			return (false);
		}
		if (nmap->flags[i]->type == 1 && !ft_is_string_numeric(argv[currentid + 1]))
		{
			printf(nmap->flags[i]->error, argv[currentid + 1]);
			exit(0);
		}
		nmap->flags[i]->actif = true;
		nmap->flags[i]->value = ft_strdup(argv[currentid + 1]);
		return (true);
		i++;
	}
	return (false);
}

BOOLEAN			load_size(t_nmap *nmap, char *arg)
{
	int size;

	if (arg[0] == '-')
		return (false);
	if (!ft_is_string_numeric(arg))
	{
		ft_fprintf(1, "ft_nmap: \"%s\" bad value for packet length\n", arg);
		exit(0);
	}
	size = ft_atoi(arg);
	if (size < nmap->sweepminsize)
	{
		ft_fprintf(1, "ft_nmap: packet length must be > %d\n", nmap->sweepminsize);
		exit(0);
	}
	if (size > MAX_PACKET_SIZE)
	{
		ft_fprintf(1, "ft_nmap: packet length must be <= %d\n", MAX_PACKET_SIZE);
		exit(0);
	}
	nmap->sweepminsize = size;
	return (true);
}

BOOLEAN			load_host(t_nmap *nmap, char *arg)
{
	struct sockaddr_in 	*in;
	int					count_ip;

	if (arg[0] == '-')
		return (false);
	if (nmap->shost != NULL)
	{
		print_help(nmap);
		exit(0);
	}
	nmap->shost = ft_strdup(arg);
	count_ip = get_count_of_host_ipv4(nmap->shost, TCP_PROTOCOL);
	in = get_sockaddr_in_ipv4(nmap->shost);
	if (in == NULL)
		return (false);
	nmap->addr = in;
	nmap->dest_ip = ft_strdup(get_hostname_ipv4(&in->sin_addr));
	if (count_ip > 1)
	{
		ft_printf("ft_nmap: Warning: %s has multiple addresses; using %s\n", nmap->shost, nmap->dest_ip);
	}
	return (true);
}

BOOLEAN			load_flags(t_nmap *nmap, int argc, char **argv)
{
	int			i;
	BOOLEAN		succes;

	i = 1;
	succes = true;
	if (has_help(argc, argv))
	{
		print_help(nmap);
		succes = false;
	}
	while (i < argc)
	{
		if (nmap->shost != NULL && i == argc - 1)
			load_size(nmap, argv[i]);
		else if (nmap->shost == NULL)
			load_host(nmap, argv[i]);
		activ_flags(nmap, argv[i]);
		if (select_value_special_flags(nmap, i, argv[i], argv, argc)) {
			i++;
		}
		i++;
	}
	return (succes);
}

static t_flag	*newflag(t_flag *f)
{
	t_flag *n;

	if (!(n = malloc(sizeof(t_flag))))
		return (NULL);
	n->actif = f->actif;
	n->name = ft_strdup(f->name);
	n->special = f->special;
	n->help = ft_strdup(f->help);
	n->value = NULL;
	n->type = f->type;
	n->error = ft_strdup(f->error);
	return (n);
}

BOOLEAN			load_flag_list(t_nmap *nmap)
{
	if (!(nmap->flags = malloc(sizeof(t_flag) * FLAGS_SIZE)))
		return (false);
	nmap->flags[0] = newflag(&(t_flag){false, "--ports",	true, "--ports    ports to scan (ex: 1-10 or 1,2,3 or 1,5-15)\n",	NULL, 2, "ft_nmap: invalid ports syntax (ex: 1-10 or 1,2,3 or 1,5-15), min-max (1-32768)\n"});
	nmap->flags[1] = newflag(&(t_flag){false, "--ip",		true, "--ip       ip addresses to scan in dot format\n",			NULL, -1, NULL});
	nmap->flags[2] = newflag(&(t_flag){false, "--file",		true, "--file     File name containing IP addresses to scan,\n",	NULL, 2, NULL});
	nmap->flags[3] = newflag(&(t_flag){false, "--speedup",	true, "--speedup  [250 max] number of parallel threads to use\n",	NULL, 1, "ft_nmap: invalid speedup (1-250)\n"});
	nmap->flags[4] = newflag(&(t_flag){false, "--scan",		true, "--scan     SYN/NULL/FIN/XMAS/ACK/UDP\n",						NULL, 2, NULL});
	return (true);
}
