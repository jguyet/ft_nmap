/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:59 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/01 23:21:35 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;
	t_list *tmp;

	new = NULL;
	start = NULL;
	tmp = NULL;
	if (lst == NULL || !f || (tmp = f(lst)) == NULL)
		return (NULL);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	start = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = new->next;
	}
	return (start);
}
