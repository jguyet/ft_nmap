/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelandnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 03:03:57 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/17 03:06:16 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdelandnew(char **del, int size)
{
	if (del)
		ft_strdel(del);
	*del = ft_strnew(size);
	return (*del);
}
