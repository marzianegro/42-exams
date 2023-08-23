/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:42:35 by mnegro            #+#    #+#             */
/*   Updated: 2023/08/23 20:35:38 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write a function named ft_printf that will mimic the real printf
	but it will manage only the following conversions: s (string),
	d (decimal), x (lowercase hexademical) */

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_fmt_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		write(1, "(null)", 6);
	while (s && s[1])
		write(1, &s[i++], 1);
	return (i);
}

void	ft_putnbr(int n, int base, int *len)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		*len += 1;
	}
	else if (n >= base)
	{
		ft_putnbr(n / base, base);
		ft_putnbr(n % base, base);
	}
	else
		write(1, n + 48, 1);
		*len += 1;
}

int	ft_fmt_d(int d)
{
	int	len;

	len = 0;
	ft_putnbr(d, 10, &len);
	return (len);
}

int	ft_fmt_x(int x)
{
	int	len;

	len = 0;
	ft_putnbr(x, 16, &len);
	return (len);
}

int	ft_formats(va_list ap, const char last)
{
	int	len;

	len = 0;
	if (last == 's')
		len += ft_fmt_s(last);
	else if (last == 'd')
		len += ft_fmt_d(last);
	else if (last == 'x')
		len += ft_fmt_x(last);
	return (len);
}

int	ft_printf(const char *last, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, last);
	while (last[i])
	{
		if (last[i] == '%')
			len += ft_formats(ap, last[i + 1]);
		i++;
	}
	va_end(ap);
	return (len);
}
