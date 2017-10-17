/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:18:14 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:18:16 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static char	*min_long(t_string *string, short base)
{
	string->is_negative = 1;
	if (base == 8)
		return (ft_strdup("1000000000000000000000"));
	else if (base == 10)
		return (ft_strdup("9223372036854775808"));
	else if (base == 16)
		return (ft_strdup("7fffffffffffffff"));
	else if (base == 32)
		return (ft_strdup("7FFFFFFFFFFFFFFF"));
	return (NULL);
}

char		*flag_l(t_string *string, short base)
{
	long long int		tmp;

	tmp = get_long_int(string);
	if (tmp < -9223372036854775807)
		return (min_long(string, base));
	if (tmp < 0)
	{
		tmp = -tmp;
		string->is_negative = 1;
	}
	if (base == 8)
		return (ft_itoabase(tmp, "01234567"));
	else if (base == 10)
		return (ft_litoa(tmp));
	else if (base == 16)
		return (ft_itoabase(tmp, "0123456789abcdef"));
	else if (base == 32)
		return (ft_itoabase(tmp, "0123456789ABCDEF"));
	return (NULL);
}

char		*flag_ul(t_string *string, short base)
{
	unsigned long int	tmp;

	tmp = get_ulong_int(string);
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
