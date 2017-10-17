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

int					compar_port(const void *p1, const void *p2)
{
	const int pp1 = *(const int*)p1;
	const int pp2 = *(const int*)p2;

	if (pp1 > pp2)
		return (1);
	return (0);
}

int					tab_length(int *tab)
{
	int i = 0;

	while (tab[i])
		i++;
	return (i);
}

static void			add_port(int *tab, int port)
{
	int i = 0;

	if (port <= 0 || port >= 32768)
		return ;
	while (tab[i])
	{
		if (tab[i] == port)
			return ;
		i++;
	}
	if (i >= 1024)
		return ;
	tab[i] = port;
}

static void			add_list_port(int *tab, char *lst)
{
	char	**split;
	int		start;
	int		max;

	if (!(split = ft_split_string(lst, "-")))
		return ;

	if (array_length(split) != 2)
		return ;
	start = ft_atoi(split[0]);
	max = ft_atoi(split[1]) + 1;
	while (start < max)
	{
		add_port(tab, start);
		start++;
	}
	free_array(split);
}

int				   *load_ports_flags(char *ports)
{
	int		*tab;
	char	**split;
	int		i;
	int		len;

	if (!(tab = malloc(sizeof(int) * (1024 + 1))))
		return (NULL);
	if (!(split = ft_split_string(ports, ",")))
		return (NULL);
	i = 0;
	while (split[i])
	{
		if (ft_strstr(split[i], "-"))
			add_list_port(tab, split[i]);
		else
			add_port(tab, ft_atoi(split[i]));
		i++;
	}
	free_array(split);
	len = tab_length(tab);
	ft_qsort(tab, len, "int*", compar_port);
	if (len <= 0)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}