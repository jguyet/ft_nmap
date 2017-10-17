/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:05:10 by jguyet            #+#    #+#             */
/*   Updated: 2016/03/18 14:05:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

int				sub(t_string *string, int i, char *s, int zero)
{
	while ((s[i + 1] && s[i + 1] == '#')
		|| (s[i + 1] && s[i + 1] == '-')
		|| (s[i + 1] && s[i + 1] == '+')
		|| (s[i + 1] && s[i + 1] == ' ')
		|| (zero == 1 && s[i + 1] && s[i + 1] == '0'))
	{
		if (s[i + 1] == '#' && !(string->sub_flags & SUB_SHARP))
			string->sub_flags += SUB_SHARP;
		else if (s[i + 1] == '-' && !(string->sub_flags & SUB_INF))
			string->sub_flags += SUB_INF;
		else if (s[i + 1] == '+' && !(string->sub_flags & SUB_SUP))
			string->sub_flags += SUB_SUP;
		else if (s[i + 1] == ' ' && !(string->sub_flags & SUB_SPACE))
			string->sub_flags += SUB_SPACE;
		else if (s[i + 1] == '0' && !(string->sub_flags & SUB_ZERO))
			string->sub_flags += SUB_ZERO;
		i++;
	}
	return (i);
}

static void		final_parse_sub(t_string *string)
{
	int		i;
	char	*tmp;

	i = 0;
	while (string->sub_num[i] && string->sub_num[i] == '-')
		i++;
	if (i > 0)
	{
		if (!(string->sub_flags & SUB_INF))
			string->sub_flags += SUB_INF;
		tmp = ft_strdup(string->sub_num + i);
		ft_bzero(string->sub_num, BUFFER_SUBNUM);
		ft_memcpy(string->sub_num, tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
}

int				add_digit(int i, t_string *t, short havestars)
{
	if (havestars != 0)
		ft_bzero(t->sub_num, BUFFER_SUBNUM);
	while (t->s[i + 1] && ft_isdigit(t->s[i + 1]))
	{
		t->sub_num[ft_strlen(t->sub_num)] = t->s[i + 1];
		i++;
	}
	return (i);
}

static int		center_parse_sub(t_string *string, int i)
{
	short point;
	short startpts;

	point = 0;
	startpts = 0;
	while ((string->s[i + 1] && ft_isdigit(string->s[i + 1]))
		|| (string->s[i + 1] && string->s[i + 1] == '.')
		|| (string->s[i + 1] && string->s[i + 1] == '*'))
	{
		if (ft_isdigit(string->s[i + 1]))
		{
			i = add_digit(i, string, startpts);
			continue ;
		}
		else if (string->s[i + 1] == '*')
		{
			i = add_wildcard(i, string, point);
			startpts++;
		}
		else if (point == 0 && ++point > 0)
			string->sub_num[ft_strlen(string->sub_num)] = '.';
		i++;
	}
	final_parse_sub(string);
	return (i);
}

int				sub_flags(t_string *string, int i)
{
	string->sub_flags = 0;
	i = sub(string, i, string->s, 1);
	i = center_parse_sub(string, i);
	i = sub(string, i, string->s, 1);
	string->left = 0;
	string->pad = ' ';
	if (string->sub_flags & SUB_INF)
	{
		string->left = 1;
		string->pad = ' ';
	}
	if (string->left == 0 && (string->sub_flags & SUB_ZERO))
		string->pad = '0';
	return (i);
}
