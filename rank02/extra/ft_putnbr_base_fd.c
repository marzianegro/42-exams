#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	len;

	len = ft_strlen(base);
	if (fd < 0)
		return ;
	if (nbr == INT_MIN)
		printf("%d", INT_MIN);
	else if (nbr < 0)
	{
		ft_putchar_fd(fd, "-");
		nbr = -nbr;
		ft_putnbr_base_fd(nbr, base, fd);
	}
	else if (nbr >= 10)
	{
		ft_putnbr_base_fd(nbr / len, &base, fd);
		ft_putnbr_base_fd(nbr % len, &base, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
