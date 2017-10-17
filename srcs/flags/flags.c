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

BOOLEAN			has_illegal_option(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			printf("ft_nmap: illegal option -- -\n");
			return (true);
		}
		i++;
	}
	return (false);
}

BOOLEAN			print_help(t_nmap *nmap)
{
	int		i;

	i = 0;
	printf("usage: ft_nmap [-");
	while (i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->special == false)
			printf("%s", nmap->flags[i]->name);
		i++;
	}
	printf("]");
	i = 0;
	while (i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->special == true)
			printf(" %s", nmap->flags[i]->help);
		i++;
	}
	printf(" host [packetlen]\n");
	return (false);
}

BOOLEAN			activ_flags(t_nmap *nmap, char *arg)
{
	int		i;
	int		o;

	i = -1;
	if (arg[0] != '-')
		return (true);
	while (++i < FLAGS_SIZE)
	{
		o = 1;
		if (nmap->flags[i]->special == true)
			continue ;
		while (o < (int)ft_strlen(arg))
		{
			if (ft_strncmp(nmap->flags[i]->name, arg + o,\
				ft_strlen(nmap->flags[i]->name)) == 0)
			{
				nmap->flags[i]->actif = true;
				break ;
			}
			o++;
		}
	}
	return (true);
}

BOOLEAN			select_value_special_flags(t_nmap *nmap,\
	int currentid, char *arg, char **argv, int argc)
{
	int		i;

	i = 0;
	if (arg[0] != '-')
		return (false);
	while (i < FLAGS_SIZE)
	{
		if (nmap->flags[i]->type == -1\
			|| nmap->flags[i]->special == false\
			|| ft_strcmp(nmap->flags[i]->name, arg + 1) != 0)
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
			char *error = ft_strjoin("ft_nmap: ", nmap->flags[i]->error);
			printf(error, argv[currentid + 1]);
			ft_strdel(&error);
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
	if (has_illegal_option(argc, argv))
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
	nmap->flags[0] = newflag(&(t_flag){false, "m", true, "[-m max_ttl]", NULL, 1, "max hops cannot be more than 255"});
	nmap->flags[1] = newflag(&(t_flag){false, "M", true, "[-M first_ttl]", NULL, 1, "ft_nmap: first ttl (%d) may not be greater than max ttl (%d)\n"});
	nmap->flags[2] = newflag(&(t_flag){false, "n", false, NULL, NULL, 0, NULL});
	nmap->flags[3] = newflag(&(t_flag){false, "d", false, NULL, NULL, 0, NULL});
	nmap->flags[4] = newflag(&(t_flag){false, "r", false, NULL, NULL, 0, NULL});
	nmap->flags[5] = newflag(&(t_flag){false, "P", true, "[-P protocol]", NULL, 0, "Cannot handle `protocol' keyword with arg `%s' (icmp, udp, tcp, gre)\n"});
	nmap->flags[6] = newflag(&(t_flag){false, "p", true, "\n[-p port]", NULL, 1, "ft_nmap: invalid port: `%d' (0-32768)\n"});
	nmap->flags[7] = newflag(&(t_flag){false, "h", false, NULL, NULL, 0, NULL});
	nmap->flags[8] = newflag(&(t_flag){false, "I", true, "[-I true or false]", NULL, 2, NULL});
	nmap->flags[9] = newflag(&(t_flag){false, "t", false, NULL, NULL, 0, NULL});
	nmap->flags[10] = newflag(&(t_flag){false, "a", false, NULL, NULL, 0, NULL});
	nmap->flags[11] = newflag(&(t_flag){false, "w", true, "[-w \"your text message\"]", NULL, 2, NULL});
	nmap->flags[12] = newflag(&(t_flag){false, "i", true, "[-i interval number of connection]", NULL, 1, "max interval connection cannot be more than 255"});
	return (true);
}
