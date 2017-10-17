/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:15:27 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:15:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		flag_default_string(t_string *string, char *tmp, short del)
{
	(void)del;
	string->tmp = ft_strdup(" ");
	string->tmp_alloc = 1;
	if (tmp == NULL)
		add_conv_string(string, "(null)");
	else
		add_conv_string(string, tmp);
}

int			conv_s(t_string *string, int i)
{
	wchar_t *tmp;

	string->wtmp = NULL;
	if (!ft_strncmp(string->converter.type, "l", 1))
	{
		tmp = get_wstring(string);
		string->wtmp = tmp;
		if (tmp == NULL)
			flag_default_string(string, NULL, 0);
		else
			flag_default_string(string, wschar_to_string(tmp), 2);
	}
	else
		flag_default_string(string, get_string(string), 0);
	return (i + 1);
}

int			conv_big_s(t_string *string, int i)
{
	wchar_t *tmp;

	string->wtmp = NULL;
	tmp = get_wstring(string);
	string->wtmp = tmp;
	if (tmp == NULL)
		flag_default_string(string, NULL, 0);
	else
		flag_default_string(string, wschar_to_string(tmp), 2);
	return (i + 1);
}
