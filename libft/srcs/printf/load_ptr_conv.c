/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ptr_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include <printf.h>

void		load_ptr_function(t_string *string)
{
	string->ptrs[s] = &conv_s;
	string->ptrs[d] = &conv_d;
	string->ptrs[c] = &conv_c;
	string->ptrs[i] = &conv_i;
	string->ptrs[x] = &conv_x;
	string->ptrs[big_x] = &conv_big_x;
	string->ptrs[big_c] = &conv_big_c;
	string->ptrs[big_s] = &conv_big_s;
	string->ptrs[p] = &conv_p;
	string->ptrs[big_d] = &conv_big_d;
	string->ptrs[o] = &conv_o;
	string->ptrs[big_o] = &conv_big_o;
	string->ptrs[u] = &conv_u;
	string->ptrs[big_u] = &conv_big_u;
	string->ptrs[f] = &conv_f;
	string->ptrs[big_f] = &conv_f;
}
