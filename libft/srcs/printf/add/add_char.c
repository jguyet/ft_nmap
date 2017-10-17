/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 13:04:56 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 13:04:58 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		add_char(t_string *string, char c)
{
	char *tmp;

	if (string->res != 0 && !(string->res % BUFFER))
	{
		tmp = ft_strnew(string->res + BUFFER);
		ft_memcpy(tmp, string->new, string->res);
		ft_strdel(&string->new);
		string->new = tmp;
	}
	string->new[string->res++] = c;
}
