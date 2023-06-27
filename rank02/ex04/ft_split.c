#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_min(size_t val1, size_t val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			min_val;
	char			*substr;

	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(1 * sizeof(char));
		if (!substr)
			return (NULL);
		return (substr);
	}
	min_val = ft_min((ft_strlen(s) - start), len);
	substr = (char *)malloc((min_val + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], ++min_val);
	return (substr);
}

static int	ft_getcount(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		else if (*s != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	if (!count)
		return (1);
	return (count + 1);
}

static int	ft_getlen(const char *s, char c, int ext_count)
{
	int	len;
	int	int_count;
	int	flag;

	len = 0;
	int_count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		if (*s != c)
		{
			if (flag == 1)
			{
				int_count++;
				flag = 0;
			}
			if (*s != c && int_count == ext_count)
				len++;
		}
		s++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		str_i;
	int		len;
	char	**str_arr;

	str_arr = (char **)malloc(ft_getcount(s, c) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	i = 0;
	str_i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = ft_getlen(s, c, (str_i + 1));
			str_arr[str_i] = ft_substr(s, i, len);
			str_i++;
			i += len;
		}
	}
	str_arr[str_i] = NULL;
	return (str_arr);
}
