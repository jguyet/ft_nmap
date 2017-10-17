/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:18:08 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:18:10 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char		*min_short(t_string *string, short base)
{
	int tmp2;

	tmp2 = 32768;
	string->is_negative = 1;
	if (base == 8)
		return (ft_itoabase(tmp2, "01234567"));
	else if (base == 10)
		return (ft_litoa(tmp2));
	else if (base == 16)
		return (ft_itoabase(tmp2, "0123456789abcdef"));
	else if (base == 32)
		return (ft_itoabase(tmp2, "0123456789ABCDEF"));
	return (NULL);
}

char		*flag_h(t_string *string, short base)
{
	short	tmp;

	tmp = get_short(string);
	if (tmp == -32768)
		return (min_short(string, base));
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

char		*flag_uh(t_string *string, short base)
{
	unsigned short	tmp;

	tmp = get_ushort(string);
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
