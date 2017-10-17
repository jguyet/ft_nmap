/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_os.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:19:20 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 07:19:22 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void	check_os(void)
{
#ifdef __linux__
	return ;
#endif
#ifdef __APPLE__
	return ;
#else
	printf("ft_nmap : is not posix.\n");
	exit(0);
#endif
}
