/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:53:26 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/22 12:53:28 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void		add_long_int(t_string *string, long int s)
{
	char *n;

	n = ft_litoa(s);
	add_string(string, n, 1);
}
