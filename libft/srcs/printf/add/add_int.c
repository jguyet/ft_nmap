/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:46:38 by frmarinh          #+#    #+#             */
/*   Updated: 2016/05/27 18:46:44 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		add_int(t_string *string, int s)
{
	char *n;

	n = ft_litoa(s);
	add_string(string, n, 1);
}

void		add_uint(t_string *string, unsigned int s)
{
	char *n;

	n = ft_uitoa(s);
	add_string(string, n, 1);
}

void		add_uint_long(t_string *string, unsigned long int s)
{
	char *n;

	n = ft_uitoa(s);
	add_string(string, n, 1);
}

void		add_ushort(t_string *string, int s)
{
	char *n;

	n = ft_litoa(s);
	add_string(string, n, 1);
}

void		add_uint_long_long(t_string *string, unsigned long long int s)
{
	char *n;

	n = ft_uitoa(s);
	add_string(string, n, 1);
}
