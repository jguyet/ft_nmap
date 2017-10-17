/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:41:51 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:41:53 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPFT_H
# define MAPFT_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <libft.h>

typedef struct		s_hash
{
	void			*data;
	void			*key;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_hashmap
{
	t_hash			**hashtable;
	BOOLEAN			(*add)();
	void			*(*get)();
	int				(*size)();
	void			(*tostring)();
	void			(*clear)();
	int				map_size;
	int				type;
}					t_hashmap;

# ifdef PROG_MAP_FT

/*
** Functions for hashMAP
*/
BOOLEAN				add_hash(t_hashmap *table, void *key, void *data);
void				*get_hash_value(t_hashmap *table, void *key);
int					get_hash_size(t_hashmap *table);
void				clear_hashtable(t_hashmap *table);

# endif

/*
** Function initialize hashMap exemple (t_hashmap *map = newStringhashmap(10);)
*/
t_hashmap			*newintegerhashmap(int size);
t_hashmap			*newstringhashmap(int size);
#endif
