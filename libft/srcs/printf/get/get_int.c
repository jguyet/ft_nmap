/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 11:45:26 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 11:45:27 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

int					get_int(t_string *t)
{
	return ((int)va_arg(t->list, int));
}

unsigned int		get_uint(t_string *t)
{
	return ((unsigned int)va_arg(t->list, unsigned int));
}

short				get_short(t_string *t)
{
	return ((short)va_arg(t->list, int));
}

unsigned short		get_ushort(t_string *t)
{
	return ((unsigned short)va_arg(t->list, unsigned int));
}

size_t				get_size_t(t_string *t)
{
	return ((size_t)va_arg(t->list, size_t));
}
