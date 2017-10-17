/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:05:41 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/15 02:06:09 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	string->base = 10;
	string->tmp = tmp;
	string->tmp_alloc = 0;
	string->is_big = 3;
	ft_bzero(string->sub_num, BUFFER_SUBNUM);
	precision(string);
}

static char		*float_conv(t_string *string, double tmp)
{
	load(string);
	if (tmp > 0)
		string->is_negative = 0;
	else
		string->is_negative = 1;
	return (ft_convert_double_to_string(tmp, string->zero > 0 \
		? string->zero : 6));
}

int				conv_f(t_string *string, int i)
{
	char *tmp;

	tmp = float_conv(string, get_float(string));
	conv_process(string, tmp);
	return (i + 1);
}
