/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_protocol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:13:17 by jguyet            #+#    #+#             */
/*   Updated: 2017/09/12 23:13:21 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

const struct protocole    *get_protocol(t_proto_enum e)
{
    int i;

    i = 0;
    while (i < MAX_PROTOCOLS)
    {
        if (protos[i].e_name == e)
            return (&protos[i]);
        i++;
    }
    return (NULL);
}

const struct protocole    *get_protocol_by_name(char *name)
{
    int i;

    i = 0;
    while (i < MAX_PROTOCOLS)
    {
        if (ft_strcmp(protos[i].name, name) == 0)
            return (&protos[i]);
        i++;
    }
    return (NULL);
}

