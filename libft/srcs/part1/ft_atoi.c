/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:12 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/03 23:49:58 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int result;
	int negatif;

	i = 0;
	result = 0;
	negatif = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] > 47 && str[i + 1] < 58)
			negatif = 1;
		i++;
	}
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		result = result * 10;
		result += (int)(str[i] - 48);
		i++;
	}
	return (negatif ? -result : result);
}
