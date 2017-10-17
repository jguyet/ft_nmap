/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:15:51 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:15:53 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	string->base = 8;
	string->tmp = tmp;
	string->tmp_alloc = 0;
	string->is_big = 4;
	precision(string);
}

int				conv_o(t_string *string, int i)
{
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ull(string, 8));
	else if (!ft_strncmp(string->converter.type, "l", 1))
		conv_process(string, flag_ul(string, 8));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uhh(string, 8));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 8));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 8));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_ull(string, 8));
	else
		conv_process(string, flag_uint(string, 8));
	return (i + 1);
}

int				conv_big_o(t_string *string, int i)
{
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ll(string, 8));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uint(string, 8));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 8));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 8));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_j(string, 8));
	else
		conv_process(string, flag_l(string, 8));
	return (i + 1);
}
