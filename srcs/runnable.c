/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 01:48:05 by jguyet            #+#    #+#             */
/*   Updated: 2017/06/06 01:48:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

#include <pthread.h>

void		process_test(t_nmap *nmap, int port)
{
	
	test_connection(nmap, port);
	
}

void		*runnable(void *arg)
{
    (void)arg;
	t_nmap *nmap = (t_nmap*)arg;

    process_test(nmap, 80);
	pthread_exit(NULL);
}

BOOLEAN        new_thread(t_nmap *nmap)
{
    pthread_t thread;

    if (pthread_create(&thread, NULL, runnable, nmap))
    {
        perror("pthread_create");
        return (false);
    }
    return (true);
}