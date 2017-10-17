/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 05:18:37 by jguyet            #+#    #+#             */
/*   Updated: 2016/06/07 05:18:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

char		*flag_z(t_string *string, short base)
{
	size_t	tmp;

	tmp = get_size_t(string);
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
