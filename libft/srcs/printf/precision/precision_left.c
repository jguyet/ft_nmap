/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:57:18 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 08:57:20 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_alt(t_string *t)
{
	if ((t->sub_flags & SUB_SHARP) && t->base == 16)
	{
		add_char(t, '0');
		if (t->is_big)
			add_char(t, 'X');
		else
			add_char(t, 'x');
		t->space -= 2;
	}
	if (t->base == 16 && t->is_big == 3)
	{
		add_string(t, "0x", 1);
	}
	if (ft_atoi(t->tmp) != 0 && (t->sub_flags & SUB_SHARP)
		&& t->base == 8)
	{
		add_char(t, '0');
		t->space -= 1;
	}
}

static void		s_flags(t_string *t)
{
	if (t->is_negative && t->base == 10)
	{
		add_char(t, '-');
		t->space -= 1;
	}
	else if ((t->sub_flags & SUB_SUP) && t->base == 10)
	{
		add_char(t, '+');
		t->space -= 1;
	}
	else if ((t->sub_flags & SUB_SPACE) && t->base == 10)
	{
		add_char(t, ' ');
		t->space -= 1;
	}
}

void			process_left(t_string *t)
{
	int		temp;

	s_flags(t);
	s_alt(t);
	t->space -= ft_strlen(t->tmp) + t->zero;
	if (t->space > 0 && t->is_big == 3)
		t->space -= 2;
	if (t->zero > 0)
	{
		temp = t->space;
		t->space = t->zero;
		if (ft_atoi(t->tmp) != 0 && (t->sub_flags & SUB_SHARP)
			&& t->base == 8)
		{
			t->space -= 1;
			temp += 1;
		}
		fill_character(t, '0');
		t->space = temp;
	}
	add_string(t, t->tmp, 2);
	fill_character(t, ' ');
}
