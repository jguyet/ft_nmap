/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:31:48 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/08 20:31:49 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char		*min_int(t_string *string, short base)
{
	long int tmp2;

	tmp2 = 2147483648;
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

char		*flag_int(t_string *string, short base)
{
	int		tmp;

	string->is_negative = 0;
	tmp = get_int(string);
	if (tmp == -2147483648)
		return (min_int(string, base));
	else if (tmp < 0)
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

char		*flag_uint(t_string *string, short base)
{
	unsigned int	tmp;

	tmp = get_uint(string);
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
