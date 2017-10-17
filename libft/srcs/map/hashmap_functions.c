/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:23:15 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/25 12:23:17 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROG_MAP_FT
#include "mapft.h"

static int	parsekey(t_hashmap *table, void *key)
{
	unsigned long int	hashkey;
	int					i;

	i = 0;
	hashkey = 0;
	if (table->type == 's')
	{
		while (hashkey < ULONG_MAX && (*(char*)key))
		{
			hashkey = hashkey << 8;
			hashkey += (*(char*)key);
			i++;
			key++;
		}
	}
	else if (table->type == 'i')
		hashkey = (unsigned long int)key;
	return (hashkey % table->map_size);
}

BOOLEAN		add_hash(t_hashmap *table, void *key, void *data)
{
	t_hash	*new;
	int		hashindex;
	t_hash	**element;

	if (!(new = (t_hash*)malloc(sizeof(struct s_hash))))
		return (false);
	new->key = key;
	new->data = data;
	new->next = NULL;
	hashindex = parsekey(table, key);
	element = &table->hashtable[hashindex];
	if (*element != NULL)
	{
		while ((*element)->next != NULL)
			element = &(*element)->next;
		(*element)->next = new;
	}
	else
		table->hashtable[hashindex] = new;
	return (true);
}

void		*get_hash_value(t_hashmap *table, void *key)
{
	int		hashindex;
	t_hash	*element;

	hashindex = parsekey(table, key);
	if (table->hashtable[hashindex] != NULL)
	{
		element = table->hashtable[hashindex];
		while (element != NULL)
		{
			if (table->type == 'i' && element->key == key)
				return (element->data);
			else if (table->type == 's'\
				&& ft_strcmp((char*)element->key, key) == 0)
				return (element->data);
			element = element->next;
		}
	}
	return (NULL);
}

int			get_hash_size(t_hashmap *table)
{
	int		i;
	int		count;
	t_hash	*element;

	i = 0;
	count = 0;
	while (i < table->map_size)
	{
		if (table->hashtable[i] != NULL)
		{
			element = table->hashtable[i];
			while (element != NULL)
			{
				element = element->next;
				count++;
			}
		}
		i++;
	}
	return (count);
}

void		clear_hashtable(t_hashmap *table)
{
	free(&table->hashtable);
	//free(&table);
}
