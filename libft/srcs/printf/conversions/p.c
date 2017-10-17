/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:15:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:15:37 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		conv_process(t_string *string, char *tmp)
{
	string->base = 16;
	string->tmp = tmp;
	string->tmp_alloc = 1;
	string->is_negative = 0;
	string->is_big = 3;
	precision(string);
}

int				conv_p(t_string *string, int i)
{
	char *tmp;

	tmp = va_arg(string->list, void *);
	if (tmp != NULL)
		tmp = ft_uitoabase((unsigned long int)tmp, "0123456789abcdef");
	else if (tmp == 0)
		tmp = ft_strdup("0");
	conv_process(string, tmp);
	return (i + 1);
}
