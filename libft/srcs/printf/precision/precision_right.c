/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:19:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/12 19:19:40 by jguyet           ###   ########.fr       */
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
	}
	if (t->base == 16 && t->is_big == 3)
		add_string(t, "0x", 1);
	else if (t->is_big && (t->sub_flags & SUB_SHARP) && t->tmp == NULL)
	{
		add_char(t, '0');
		t->space -= 1;
	}
	if (t->base == 8)
		alt_eight(t);
}

static void		signe(t_string *t)
{
	if (t->base != 10)
		return ;
	if (((t->sub_flags & SUB_INF) && t->base == 10)
		|| (t->is_negative && t->base == 10))
		add_char(t, '-');
	else if ((t->sub_flags & SUB_SUP) && t->base == 10)
		add_char(t, '+');
	else if ((t->sub_flags & SUB_SPACE) && t->base == 10)
		add_char(t, ' ');
}

static void		if_flags(t_string *t)
{
	if (t->base == 10)
	{
		if_flag_ten(t);
		return ;
	}
	if (t->base == 16)
	{
		if_flag_sixteen(t);
		return ;
	}
	if (t->base == 8)
	{
		is_flag_eight(t);
		return ;
	}
}

static void		finaly_zero(int tmp, t_string *t)
{
	if (t->is_big != 3)
		fill_character(t, '0');
	if (t->is_big == 3 && tmp > 0)
		fill_character(t, '0');
	add_string(t, t->tmp, 2);
	if (t->is_big == 3 && tmp == 0)
		fill_character(t, '0');
}

void			process_right(t_string *t)
{
	int tmp;

	tmp = t->space;
	t->space -= ft_strlen(t->tmp) + t->zero;
	if (t->space > 0 && t->is_big == 3)
		t->space -= 2;
	if_flags(t);
	if ((t->sub_flags & SUB_ZERO))
	{
		if (t->zero > 0)
			fill_character(t, ' ');
	}
	else if (t->pad == ' ')
	{
		fill_character(t, ' ');
		t->space = 0;
	}
	signe(t);
	s_alt(t);
	t->space += t->zero;
	finaly_zero(tmp, t);
}
