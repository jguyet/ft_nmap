/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:17:00 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/15 02:25:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		s_strcal(char **s, long n)
{
	if (n < 0)
	{
		*s = ft_dstrjoin_char(*s, '-', 1);
		n = n * -1;
	}
	if (n < 10)
	{
		*s = ft_dstrjoin_char(*s, '0' + n, 1);
	}
	else
	{
		s_strcal(s, n / 10);
		*s = ft_dstrjoin_char(*s, '0' + n % 10, 1);
	}
}

static void		s_strcal_p(char **s, long n, long *prec)
{
	if (n < 0)
	{
		*s = ft_dstrjoin_char(*s, '-', 1);
		n = n * -1;
	}
	if (n < 10)
	{
		*s = ft_dstrjoin_char(*s, '0' + n, 1);
	}
	else
	{
		--(*prec);
		s_strcal_p(s, n / 10, prec);
		*s = ft_dstrjoin_char(*s, '0' + n % 10, 1);
	}
}

long int		s_get_pprec(long prec)
{
	long int	pprec;

	if (prec == -1)
		prec = 6;
	pprec = (prec == 0) ? 0 : 1;
	if (prec > 18)
		prec = 18;
	while (prec)
	{
		pprec = pprec * 10;
		--prec;
	}
	return (pprec);
}

static void		s_point(long t, long int pprec, long prec, char **str)
{
	prec = (prec == -1) ? 6 : prec;
	*str = ft_dstrjoin_char(*str, '.', 1);
	--prec;
	while (t < pprec / 10 && prec > 0)
	{
		--prec;
		pprec /= 10;
		*str = ft_dstrjoin_char(*str, '0', 1);
	}
	s_strcal_p(str, t, &prec);
	while (prec > 0)
	{
		*str = ft_dstrjoin_char(*str, '0', 1);
		--prec;
	}
}

char			*ft_convert_double_to_string(double n, unsigned int prec)
{
	char		*str;
	long		t;
	long int	pprec;

	str = ft_strnew(0);
	pprec = s_get_pprec(prec);
	s_strcal(&str, n);
	if (pprec == 0)
		return (str);
	n = (n < 0) ? -n : n;
	t = ((n - ((long)n) + 1.0 / (pprec * pprec))) * pprec;
	s_point(t, pprec, prec, &str);
	return (str);
}
