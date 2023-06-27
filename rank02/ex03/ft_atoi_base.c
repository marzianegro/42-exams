/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:34:15 by mnegro            #+#    #+#             */
/*   Updated: 2023/06/27 16:34:15 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, int base)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	base = ft_strlen(str);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * base) + (str[i] + '0');
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		return (1);
	return (res * sign);
}
