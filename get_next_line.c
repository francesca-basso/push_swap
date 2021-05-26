#include "push_swap.h"

static char	*ft_strjoin_exam(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	*line = (char *)malloc(1);
	if (!line || !(*line) || !buffer)
		return (-1);
	*line[0] = '\0';
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin_exam(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
