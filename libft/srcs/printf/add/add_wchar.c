/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 10:51:05 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 10:51:08 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <wchar.h>

void	add_wchar(t_string *t, wchar_t c)
{
	if (c <= 0x7F)
		add_char(t, c);
	else if (c <= 0x7FF)
	{
		add_char(t, (c >> 6) + 0xC0);
		add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		add_char(t, (c >> 12) + 0xE0);
		add_char(t, ((c >> 6) & 0x3F) + 0x80);
		add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		add_char(t, (c >> 18) + 0xE0);
		add_char(t, ((c >> 12) & 0x3F) + 0x80);
		add_char(t, ((c >> 6) & 0x3F) + 0x80);
		add_char(t, (c & 0x3F) + 0x80);
	}
}

char	*wchar_to_string(wchar_t c)
{
	char *ret;

	ret = ft_strnew(0);
	if (c <= 0x7F)
		ret = ft_dstrjoin_char(ret, c, 1);
	else if (c <= 0x7FF)
	{
		ret = ft_dstrjoin_char(ret, (c >> 6) + 0xC0, 1);
		ret = ft_dstrjoin_char(ret, (c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0xFFFF)
	{
		ret = ft_dstrjoin_char(ret, (c >> 12) + 0xE0, 1);
		ret = ft_dstrjoin_char(ret, ((c >> 6) & 0x3F) + 0x80, 1);
		ret = ft_dstrjoin_char(ret, (c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0x10FFFF)
	{
		ret = ft_dstrjoin_char(ret, (c >> 18) + 0xE0, 1);
		ret = ft_dstrjoin_char(ret, ((c >> 12) & 0x3F) + 0x80, 1);
		ret = ft_dstrjoin_char(ret, ((c >> 6) & 0x3F) + 0x80, 1);
		ret = ft_dstrjoin_char(ret, (c & 0x3F) + 0x80, 1);
	}
	return (ret);
}

char	*wschar_to_string(wchar_t *s)
{
	int		i;
	char	*string;

	i = 0;
	string = ft_strnew(0);
	while (s[i])
	{
		string = ft_dstrjoin(string, wchar_to_string(s[i]), 3);
		i++;
	}
	return (string);
}

int		ft_wlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

int		ft_wslen(wchar_t *c)
{
	int i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
