/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:16:09 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:16:11 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	if (tmp == NULL)
		return ;
	string->base = 16;
	string->tmp = tmp;
	string->tmp_alloc = 0;
	string->is_negative = 0;
	if (string->sub_flags & SUB_SUP)
		string->sub_flags -= SUB_SUP;
	if (string->sub_flags & SUB_SPACE)
		string->sub_flags -= SUB_SPACE;
	if (tmp != NULL && (string->sub_flags & SUB_SHARP) \
		&& !ft_strcmp("0", tmp))
		string->sub_flags -= SUB_SHARP;
	precision(string);
}

int				conv_x(t_string *string, int i)
{
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ull(string, 16));
	else if (!ft_strncmp(string->converter.type, "l", 1))
		conv_process(string, flag_ul(string, 16));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uhh(string, 16));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 16));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 16));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_ull(string, 16));
	else
		conv_process(string, flag_uint(string, 16));
	return (i + 1);
}

int				conv_big_x(t_string *string, int i)
{
	string->is_big = 1;
	if (!ft_strncmp(string->converter.type, "ll", 2))
		conv_process(string, flag_ull(string, 32));
	else if (!ft_strncmp(string->converter.type, "l", 1))
		conv_process(string, flag_ul(string, 32));
	else if (!ft_strncmp(string->converter.type, "hh", 2))
		conv_process(string, flag_uhh(string, 32));
	else if (!ft_strncmp(string->converter.type, "h", 1))
		conv_process(string, flag_uh(string, 32));
	else if (!ft_strncmp(string->converter.type, "z", 1))
		conv_process(string, flag_z(string, 32));
	else if (!ft_strncmp(string->converter.type, "j", 1))
		conv_process(string, flag_ull(string, 32));
	else
		conv_process(string, flag_uint(string, 32));
	return (i + 1);
}
