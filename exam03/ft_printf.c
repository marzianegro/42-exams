/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:42:35 by mnegro            #+#    #+#             */
/*   Updated: 2023/08/30 11:59:20 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write a function named ft_printf that will mimic the real printf
	but it will manage only the following conversions: s (string),
	d (decimal), x (lowercase hexademical) */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (str && *str)
		*len += write(1, str++, 1);
}

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int	base_len;
	
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base, len);
	*len += write(1, &base[nbr % base_len], 1);
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
		{
			i++;
			if (last[i] == 's')
				ft_putstr(va_arg(ap, char *), &len);
			else if (last[i] == 'd')
				ft_putnbr_base((long int)va_arg(ap, int), "0123456789", &len);
			else if (last[i] == 'x')
				ft_putnbr_base((long int)va_arg(ap, int), "0123456789abcdef", &len);
		}
		else
			len += write(1, &last[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("Mine: %d\n", ft_printf("%d\n", 42));
	printf("OG: %d\n", printf("%d\n", 42));
	return (0);
}
