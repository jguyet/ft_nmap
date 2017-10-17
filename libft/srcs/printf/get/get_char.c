/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 11:45:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 11:45:37 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <wchar.h>

char			get_char(t_string *t)
{
	return ((char)get_int(t));
}

unsigned char	get_uchar(t_string *t)
{
	return ((unsigned char)get_int(t));
}

wchar_t			get_wchar(t_string *t)
{
	return ((wchar_t)va_arg(t->list, wchar_t));
}

intmax_t		get_intmax_t(t_string *t)
{
	return ((intmax_t)va_arg(t->list, intmax_t));
}
