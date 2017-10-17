/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:55:48 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/17 14:25:57 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include <printf.h>
#include <unistd.h>

static void	put_printf(int fd, t_string *string)
{
	unsigned int i;

	i = 0;
	if (BONUS)
	{
		modif_colors(string);
	}
	while (i < string->res)
	{
		write(fd, string->new + i, 1);
		i++;
	}
}

int			ft_printf(const char *s, ...)
{
	t_string	*string;
	int			res;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (-1);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->tmp_alloc = 0;
	string->tmp = NULL;
	string->size = BUFFER;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	put_printf(1, string);
	ft_strdel(&string->new);
	va_end(string->list);
	res = string->res;
	free(string);
	return (res);
}

int			ft_fprintf(int fd, const char *s, ...)
{
	t_string	*string;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (-1);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->tmp_alloc = 0;
	string->tmp = NULL;
	string->size = BUFFER;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	put_printf(fd, string);
	ft_strdel(&string->new);
	va_end(string->list);
	return (string->res);
}

int			ft_asprintf(char **ptr, const char *s, ...)
{
	t_string	*string;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (-1);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->tmp_alloc = 0;
	string->tmp = NULL;
	string->size = BUFFER;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	*ptr = string->new;
	va_end(string->list);
	return (string->res);
}

char		*ft_sprintf(const char *s, ...)
{
	t_string	*string;
	char		*res;

	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (NULL);
	string->s = (char*)s;
	string->res = 0;
	string->new = ft_strnew(BUFFER);
	string->tmp_alloc = 0;
	string->tmp = NULL;
	string->size = BUFFER;
	load_ptr_function(string);
	va_start(string->list, (char*)s);
	parse_flags(string, 0);
	res = string->new;
	va_end(string->list);
	return (res);
}
