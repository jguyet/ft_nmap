/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_flags_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:57:37 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/27 16:57:40 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

int				add_wildcard(int i, t_string *t, short point)
{
	int nbr;

	nbr = get_int(t);
	if (nbr < 0)
	{
		nbr = -nbr;
		if (point == 0 && !(t->sub_flags & SUB_INF))
			t->sub_flags += SUB_INF;
		else
			nbr = -nbr;
	}
	if (point == 0 && t->sub_num[0] != '\0')
		ft_bzero(t->sub_num, BUFFER_SUBNUM);
	if (point > 0 || sub(t, -1, t->sub_num, 1) == -1)
		ft_strcpy(t->sub_num, ft_litoa(nbr));
	else
		ft_strcpy(t->sub_num, ft_litoa(nbr));
	return (i);
}
