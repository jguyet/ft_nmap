/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purcente.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:20:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:20:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	string->is_big = 5;
	string->tmp_alloc = 0;
	if (!ft_strcmp(string->sub_num, "0.0") || !ft_strcmp(string->sub_num, ".0"))
	{
		ft_bzero(string->sub_num, BUFFER_SUBNUM);
	}
	add_conv_string(string, tmp);
}

int				conv_purcent(t_string *string, int i)
{
	conv_process(string, ft_strdup("%"));
	return (i + 1);
}
