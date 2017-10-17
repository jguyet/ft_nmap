/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:46:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/04 17:46:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "mapft.h"
#include "libft.h"

static void	cmpqsortstring(char **base, int *tmp, size_t size,\
			int (*compar)(const void*, const void*))
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (base[i] != NULL && *tmp != -1\
			&& compar(base[*tmp], base[i]) > 0)
			*tmp = i;
		else if (base[i] != NULL && *tmp == -1)
			*tmp = i;
		i++;
	}
}

static void	asigncurrenttabtobase(char **base, char **tab, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		base[i] = NULL;
		if (tab[i] != NULL)
		{
			base[i] = tab[i];
		}
		i++;
	}
	free(tab);
}

static void	ft_qsort_string(char **base, size_t mmemb,\
			int (*compar)(const void *, const void *), char **tab)
{
	int		tmp;
	size_t	count;

	if (tab == NULL)
		return ;
	count = 0;
	while (1)
	{
		tmp = -1;
		cmpqsortstring(base, &tmp, mmemb, compar);
		if (tmp == -1)
			break ;
		tab[count++] = base[tmp];
		base[tmp] = NULL;
	}
	asigncurrenttabtobase(base, tab, mmemb);
}

static void	ft_qsort_integer(int *base, size_t mmemb,\
			int (*compar)(const void *, const void *))
{
	(void)compar;
	(void)mmemb;
	(void)base;
}

void		ft_qsort(void *base, size_t mmemb, char *type,\
			int (*compar)(const void *, const void *))
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = malloc(sizeof(char*) * mmemb);
	while (i < mmemb)
		tmp[i++] = NULL;
	if (strcmp(type, "int*") == 0)
		ft_qsort_integer(base, mmemb, compar);
	else if (strcmp(type, "char*") == 0)
		ft_qsort_string(base, mmemb, compar, tmp);
}
