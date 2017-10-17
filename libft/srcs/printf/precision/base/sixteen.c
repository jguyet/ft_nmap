/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixteen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 04:29:53 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/14 04:30:10 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char			if_flag_sixteen(t_string *t)
{
	if ((t->sub_flags & SUB_SHARP))
		t->space -= 2;
	return (1);
}
