/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 02:44:03 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/08 02:51:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddend(t_list **list, t_list *new)
{
	t_list *tmp;

	if (list && *list && new)
	{
		tmp = (*list);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
