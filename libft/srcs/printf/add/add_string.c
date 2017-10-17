/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:52:54 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 12:52:56 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void	check_if_buffer_is_empty(t_string *string, size_t o)
{
	char			*tmp;

	if (string->size - string->res < o && o < BUFFER)
	{
		tmp = ft_strnew(string->res + BUFFER);
		ft_memcpy(tmp, string->new, string->res);
		ft_strdel(&string->new);
		string->new = tmp;
		string->size = string->res + BUFFER;
	}
	else if (string->size - string->res < o)
	{
		tmp = ft_strnew(string->res + o + BUFFER);
		ft_memcpy(tmp, string->new, string->res);
		ft_strdel(&string->new);
		string->new = tmp;
		string->size = string->res + o + BUFFER;
	}
}

void		add_string(t_string *string, char *s, int del)
{
	unsigned int	i;
	unsigned int	o;

	i = 0;
	o = ft_strlen(s);
	if (o == 0)
		return ;
	check_if_buffer_is_empty(string, o);
	while (i < o)
		string->new[string->res++] = s[i++];
	if (del == 2 || del == 3)
		ft_strdel(&s);
}
