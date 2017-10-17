/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 06:48:50 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/21 06:48:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_outstring(char **ptr, int len)
{
	char	*tmp;
	int		i;

	if (len <= 0)
		return ;
	tmp = *ptr;
	i = len;
	while (tmp[i])
	{
		tmp[i - len] = tmp[i];
		i++;
	}
	i -= len;
	while (tmp[i])
		tmp[i++] = '\0';
}
