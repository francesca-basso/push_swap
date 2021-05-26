#include "push_swap.h"

void	make_ras(int *stack, char what_stack, t_program *program)
{
	while (program->num_of_moves > 0)
	{
		ft_ra_rb(stack, what_stack, program);
		program->num_of_moves--;
	}
}

void	make_rras(int *stack, char what_stack, t_program *program)
{
	while (program->num_of_moves > 0)
	{
		ft_rra_rrb(stack, what_stack, program);
		program->num_of_moves--;
	}
}

void	put_max_in_a(int *stack_a, int *stack_b, t_program *program)
{
	while (program->size_b)
	{
		program->index_max = get_index_max(stack_b, 'b', program);
		if (program->index_max <= program->size_b / 2)
		{
			program->num_of_moves = program->index_max;
			make_ras(stack_b, 'b', program);
			ft_pa(stack_a, stack_b, program);
		}
		else
		{
			program->num_of_moves = program->size_b - program->index_max;
			make_rras(stack_b, 'b', program);
			ft_pa(stack_a, stack_b, program);
		}
	}
}
