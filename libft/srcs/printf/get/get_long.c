/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:07:31 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 12:07:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

unsigned long				get_ulong(t_string *t)
{
	return ((unsigned long)va_arg(t->list, unsigned long));
}

long int					get_long_int(t_string *t)
{
	return ((long int)va_arg(t->list, long int));
}

unsigned long int			get_ulong_int(t_string *t)
{
	return ((unsigned long int)va_arg(t->list, unsigned long int));
}

long long int				get_long_long_int(t_string *t)
{
	return ((long long int)va_arg(t->list, long long int));
}

unsigned long long int		get_ulong_long_int(t_string *t)
{
	return ((unsigned long long int)va_arg(t->list, unsigned long long int));
}
