/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:15:42 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:15:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	string->base = 10;
	string->tmp = tmp;
	string->tmp_alloc = 0;
	precision(string);
}

int				conv_d(t_string *string, int i)
{
	if (!ft_strncmp("ll", string->converter.type, 2))
		conv_process(string, flag_ll(string, 10));
	else if (!ft_strncmp("l", string->converter.type, 1))
		conv_process(string, flag_l(string, 10));
	else if (!ft_strncmp("hh", string->converter.type, 2))
		conv_process(string, flag_hh(string, 10));
	else if (!ft_strncmp("h", string->converter.type, 1))
		conv_process(string, flag_h(string, 10));
	else if (!ft_strncmp("z", string->converter.type, 1))
		conv_process(string, flag_ll(string, 10));
	else if (!ft_strncmp("j", string->converter.type, 1))
		conv_process(string, flag_j(string, 10));
	else
		conv_process(string, flag_int(string, 10));
	return (i + 1);
}

int				conv_i(t_string *string, int i)
{
	if (!ft_strncmp("ll", string->converter.type, 2))
		conv_process(string, flag_ll(string, 10));
	else if (!ft_strncmp("l", string->converter.type, 1))
		conv_process(string, flag_l(string, 10));
	else if (!ft_strncmp("hh", string->converter.type, 2))
		conv_process(string, flag_hh(string, 10));
	else if (!ft_strncmp("h", string->converter.type, 1))
		conv_process(string, flag_h(string, 10));
	else if (!ft_strncmp("z", string->converter.type, 1))
		conv_process(string, flag_ll(string, 10));
	else if (!ft_strncmp("j", string->converter.type, 1))
		conv_process(string, flag_j(string, 10));
	else
		conv_process(string, flag_int(string, 10));
	return (i + 1);
}

int				conv_big_d(t_string *string, int i)
{
	if (!ft_strncmp("ll", string->converter.type, 2))
		conv_process(string, flag_ll(string, 10));
	else if (!ft_strncmp("l", string->converter.type, 1))
		conv_process(string, flag_l(string, 10));
	else if (!ft_strncmp("hh", string->converter.type, 2))
		conv_process(string, flag_uint(string, 10));
	else if (!ft_strncmp("h", string->converter.type, 1))
		conv_process(string, flag_uh(string, 10));
	else if (!ft_strncmp("z", string->converter.type, 1))
		conv_process(string, flag_z(string, 10));
	else if (!ft_strncmp("j", string->converter.type, 1))
		conv_process(string, flag_j(string, 10));
	else
		conv_process(string, flag_l(string, 10));
	return (i + 1);
}
