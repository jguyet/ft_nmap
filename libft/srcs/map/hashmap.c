/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:42:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROG_MAP_FT
#include "mapft.h"

void		tostring_hashtable(t_hashmap *map)
{
	(void)map;
}

t_hashmap	*newintegerhashmap(int size)
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_hash;
	new->get = get_hash_value;
	new->size = get_hash_size;
	new->clear = clear_hashtable;
	new->tostring = tostring_hashtable;
	new->map_size = size;
	new->type = 'i';
	if (!(new->hashtable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (i++ < new->map_size)
		new->hashtable[i] = NULL;
	return (new);
}

t_hashmap	*newstringhashmap(int size)
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_hash;
	new->get = get_hash_value;
	new->size = get_hash_size;
	new->clear = clear_hashtable;
	new->tostring = tostring_hashtable;
	new->map_size = size;
	new->type = 's';
	if (!(new->hashtable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (i++ < new->map_size)
		new->hashtable[i] = NULL;
	return (new);
}
