/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 04:28:08 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/14 04:28:40 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char			alt_eight(t_string *t)
{
	if (ft_atoi(t->tmp) != 0 \
		&& (t->sub_flags & SUB_SHARP))
	{
		add_char(t, '0');
		t->space -= 1;
	}
	else if (t->tmp != NULL && !ft_strcmp(t->tmp, "0"))
	{
		t->tmp = ft_strdelandnew(&t->tmp, 0);
		t->space++;
	}
	return (1);
}

char			is_flag_eight(t_string *t)
{
	if (t->zero <= (short)ft_strlen(t->tmp) \
		&& (t->sub_flags & SUB_SHARP))
		t->space -= 1;
	return (1);
}
