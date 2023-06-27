/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:31:01 by mnegro            #+#    #+#             */
/*   Updated: 2023/06/27 16:31:02 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	str[10];

	str = "0123456789";
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &str[nbr % 10], 1);
}

int	main(void)
{
	int	num;

	num = 1;
	while (num <= 100)
	{
		if (num % 3 == 0)
			write(1, "fizz", 4);
		else if (num % 5 == 0)
			write(1, "buzz", 4);
		else if (num % 3 == 0 && num % 5 == 0)
			write(1, "fizzbuzz", 8);
		else
			ft_putnbr(num);
		write(1, "\n", 1);
		num++;
	}
	return (0);
}
