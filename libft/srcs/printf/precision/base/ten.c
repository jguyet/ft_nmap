/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 04:28:52 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/14 04:29:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char			if_flag_ten(t_string *t)
{
	if (((t->sub_flags & SUB_INF)) || t->is_negative)
		t->space -= 1;
	else if ((t->sub_flags & SUB_SUP))
		t->space -= 1;
	else if ((t->sub_flags & SUB_SPACE))
		t->space -= 1;
	else
		return (0);
	return (1);
}
