/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:16:15 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:16:17 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		flag_default_char(t_string *string, char tmp)
{
	add_conv_char(string, tmp);
}

int			conv_c(t_string *string, int i)
{
	wchar_t tmp;

	if (!ft_strncmp(string->converter.type, "l", 1))
	{
		tmp = get_wchar(string);
		if (tmp == 0)
			flag_default_char(string, 0);
		else
			add_conv_wchar(string, tmp);
	}
	else
		flag_default_char(string, get_char(string));
	return (i + 1);
}

int			conv_big_c(t_string *string, int i)
{
	wchar_t	tmp;

	tmp = 0;
	tmp = get_wchar(string);
	if (tmp == 0)
		flag_default_char(string, 0);
	else
		add_conv_wchar(string, tmp);
	return (i + 1);
}
