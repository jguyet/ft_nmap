/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:16:00 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:16:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	if ((string->sub_flags & SUB_SPACE))
		string->sub_flags -= SUB_SPACE;
	if ((string->sub_flags & SUB_SUP))
		string->sub_flags -= SUB_SUP;
	string->base = 10;
	string->tmp = tmp;
	string->tmp_alloc = 0;
	precision(string);
}

int				conv_u(t_string *string, int i)
{
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ull(string, 10));
	else if (!ft_strncmp(string->converter.type, "l", 1))
		conv_process(string, flag_ul(string, 10));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uhh(string, 10));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 10));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 10));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_ull(string, 10));
	else
		conv_process(string, flag_uint(string, 10));
	return (i + 1);
}

int				conv_big_u(t_string *string, int i)
{
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ull(string, 10));
	else if (!ft_strncmp(string->converter.type, "l", 1))
		conv_process(string, flag_ul(string, 10));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uint(string, 10));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 10));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 10));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_j(string, 10));
	else
		conv_process(string, flag_ul(string, 10));
	return (i + 1);
}
