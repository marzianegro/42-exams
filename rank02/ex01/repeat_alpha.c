/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:31:22 by mnegro            #+#    #+#             */
/*   Updated: 2023/06/27 16:31:23 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_repeat_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ft_putchar(s[i], s[i] + 1 - 'a');
		else if (s[i] >= 'A' && s[i] <= 'Z')
			ft_putchar(s[i], s[i] + 1 - 'A');
		else
			write(1, &s, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
