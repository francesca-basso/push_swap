#include "push_swap.h"

void	free_program(t_program *program)
{
	int	i;

	if (program->argv_arg == 0)
	{
		i = 0;
		while (program->vars[i])
		{
			free(program->vars[i]);
			i++;
		}
		free(program->vars[i]);
	}
	free(program->vars);
	free(program->stack_a);
	free(program->stack_b);
}

void	exit_program(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	find_duplicates(int *stack_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
				exit_program();
			j++;
		}
		i++;
	}
}

void	check_valid_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '-' && is_space(s[i]) == 0)
			exit_program();
		i++;
	}
}
