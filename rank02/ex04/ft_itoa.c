#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int		num;
	int		len;
	char	*str;

	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return(NULL);
		str[0] = '0';
		str[1] = '\0';
		return(str);
	}
	num = n;
	while (num)
	{
		num /= 10;
		len++;
	}
	if (n < 0)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return(NULL);
	str[len + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		--len;
		str[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return(str);
}
