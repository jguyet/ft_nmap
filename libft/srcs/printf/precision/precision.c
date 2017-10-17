/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:56:57 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 08:56:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void			load(t_string *t)
{
	if (t->tmp != NULL && t->tmp[0] == '0')
	{
		if (!ft_strcmp(t->sub_num, ".") || !ft_strcmp(t->sub_num, ".0")
			|| !ft_strcmp(t->sub_num, "0.0") || !ft_strcmp(t->sub_num, "0."))
		{
			if (t->tmp_alloc == 1)
				ft_strdel(&t->tmp);
			t->tmp = NULL;
			t->tmp_alloc = 0;
		}
	}
	if (ft_strlen(t->sub_num) == 0 || !ft_strcmp(t->sub_num, "."))
	{
		t->space = 0;
		t->zero = 0;
		return ;
	}
	t->space = ft_atoi(t->sub_num);
	if (t->space == 0 && t->sub_num[0] == '.')
		t->zero = ft_atoi(t->sub_num + 1);
	else
		t->zero = ft_atoi(t->sub_num + ft_nbrlen(t->space) + 1);
}

void			precision(t_string *t)
{
	load(t);
	if (t->zero < 0)
		t->zero = 1;
	else
		t->pad = ' ';
	t->zero = ft_max(0, t->zero - (t->tmp == NULL ? 0 : 1));
	if (t->left == 0)
		process_right(t);
	else
		process_left(t);
}
