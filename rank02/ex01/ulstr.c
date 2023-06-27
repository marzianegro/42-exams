/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:31:46 by mnegro            #+#    #+#             */
/*   Updated: 2023/06/27 16:31:47 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_reverse(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		else if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		i++;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	char	*s;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	s = ft_reverse(argv[1]);
	ft_putstr(s);
	return (0);
}
