/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 03:23:10 by jguyet            #+#    #+#             */
/*   Updated: 2017/05/30 03:23:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

/*
** retourne la somme de total d'octet libre de (void* b)
** sur la longueur (int len)
*/
unsigned short checksum(void *b, int len)
{
	u_short	*buf;
	u_short	low;
	u_short	high;
	u_int	sum;

	buf = b;
	sum = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += buf[0] & 0xFF;
	low = (sum & 0xFFFF);			/* prend les 2 octet de droite					*/
	high = (sum >> 16);				/* prend les 2 octet de gauche					*/
	sum = high + low;				/* aditionne le tout							*/
	return ((unsigned short)~sum);	/* inverse les bits actif et cast en unsigned	*/
}
