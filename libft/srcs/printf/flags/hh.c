/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:18:01 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:18:03 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static char	*min_char(t_string *string, short base)
{
	string->is_negative = 1;
	if (base == 8)
		return (ft_strdup("200"));
	else if (base == 10)
		return (ft_strdup("128"));
	else if (base == 16)
		return (ft_strdup("80"));
	else if (base == 32)
		return (ft_strdup("80"));
	return (NULL);
}

char		*flag_hh(t_string *string, short base)
{
	char	tmp;

	tmp = get_char(string);
	if (tmp < -127)
		return (min_char(string, base));
	if (tmp < 0)
	{
		tmp = -tmp;
		string->is_negative = 1;
	}
	if (base == 8)
		return (ft_itoabase(tmp, "01234567"));
	else if (base == 10)
		return (ft_itoa(tmp));
	else if (base == 16)
		return (ft_itoabase(tmp, "0123456789abcdef"));
	else if (base == 32)
		return (ft_itoabase(tmp, "0123456789ABCDEF"));
	return (NULL);
}

char		*flag_uhh(t_string *string, short base)
{
	unsigned char	tmp;

	tmp = get_uchar(string);
	string->is_negative = 0;
	if (base == 8)
		return (ft_uitoabase(tmp, "01234567"));
	else if (base == 10)
		return (ft_uitoa(tmp));
	else if (base == 16)
		return (ft_uitoabase(tmp, "0123456789abcdef"));
	else if (base == 32)
		return (ft_uitoabase(tmp, "0123456789ABCDEF"));
	return (NULL);
}
