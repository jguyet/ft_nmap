/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conv_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:13:45 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/08 16:13:46 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_trunc(char **s, int length, wchar_t *wtmp)
{
	int		size;
	int		index;

	size = (length < 0) ? -length : length;
	if (*s == NULL)
		return ;
	index = 0;
	if (wtmp != NULL)
	{
		size = 0;
		*s = ft_strnew(0);
		while (*s != NULL && (size + ft_wlen(wtmp[index])) <= length)
		{
			size += ft_wlen(wtmp[index]);
			*s = ft_strjoin(*s, wchar_to_string(wtmp[index++]));
		}
	}
	else
		*s = ft_strndup(*s, length);
}

void			fill_character(t_string *t, char c)
{
	while (t->space > 0)
	{
		add_char(t, c);
		t->space--;
	}
}

void			add_conv_string(t_string *t, char *s)
{
	size_t	len;

	load(t);
	len = ft_strlen(s);
	if (t->zero > 0 || !ft_strcmp(t->sub_num, ".0") \
		|| !ft_strcmp(t->sub_num, "0.0"))
	{
		s_trunc(&s, t->zero, t->wtmp);
		len = ft_strlen(s);
	}
	else if (ft_strlen(t->sub_num) > 0 \
		&& t->sub_num[ft_strlen(t->sub_num) - 1] == '.' && t->is_big != 5)
	{
		if ((s = ft_strnew(0)))
			return ;
		len = 0;
	}
	if ((t->space -= len) < 0)
		return ((void)add_string(t, s, 0));
	if (t->left == 0)
		fill_character(t, t->pad);
	add_string(t, s, 0);
	if (t->left)
		fill_character(t, t->pad);
}

void			add_conv_char(t_string *t, char c)
{
	load(t);
	if ((t->space -= 1) < 0)
		return (add_char(t, c));
	if (t->left == 0)
		fill_character(t, t->pad);
	add_char(t, c);
	if (t->left)
		fill_character(t, t->pad);
}

void			add_conv_wchar(t_string *t, wchar_t c)
{
	load(t);
	if ((t->space -= 1) < 0)
		return (add_wchar(t, c));
	if (t->left == 0)
		fill_character(t, t->pad);
	add_wchar(t, c);
	if (t->left)
		fill_character(t, t->pad);
}
