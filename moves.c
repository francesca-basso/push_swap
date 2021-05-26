#include "push_swap.h"

void	ft_rra_rrb(int *stack, char what_stack, t_program *program)
{
	int	i;
	int	size;
	int	temp;

	if (what_stack == 'a')
	{
		ft_putstr("rra\n");
		size = program->size_a;
	}
	else
	{
		ft_putstr("rrb\n");
		size = program->size_b;
	}
	temp = stack[size - 1];
	i = size - 1;
	while (i >= 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	program->moves++;
}
