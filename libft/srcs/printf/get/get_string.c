/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 11:45:46 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 11:45:48 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <wchar.h>

char		*get_string(t_string *t)
{
	return ((char*)va_arg(t->list, char *));
}

wchar_t		*get_wstring(t_string *t)
{
	return ((wchar_t*)va_arg(t->list, wchar_t *));
}
