#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				seg;
	unsigned int	ret;

	i = 0;
	seg = 1;
	ret = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			seg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		if (ret > INT_MAX)
			return (0);
		i++;
	}
	return (ret * seg);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	r1;
	unsigned char	r2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			r1 = (unsigned char)s1[i];
			r2 = (unsigned char)s2[i];
			return (r1 - r2);
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
