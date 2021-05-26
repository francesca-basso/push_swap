#include "push_swap.h"

void	sort_3_nums(int *stack_a, char what_stack, t_program *program)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[0] < stack_a[2])
		ft_sa_sb(stack_a, what_stack, program);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
	{
		ft_sa_sb(stack_a, what_stack, program);
		ft_rra_rrb(stack_a, what_stack, program);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[0] > stack_a[2])
		ft_ra_rb(stack_a, what_stack, program);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] < stack_a[2])
	{
		ft_sa_sb(stack_a, what_stack, program);
		ft_ra_rb(stack_a, what_stack, program);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] > stack_a[2])
		ft_rra_rrb(stack_a, what_stack, program);
}

void	sort_5_nums(int *stack_a, int *stack_b, t_program *program)
{
	int	j;

	j = 0;
	while (j < 2)
	{
		program->index_min = get_index_min(stack_a, program->size_a);
		if (program->index_min <= program->size_a / 2)
		{
			program->num_of_moves = program->index_min;
			make_ras(stack_a, 'a', program);
			ft_pb(stack_a, stack_b, program);
		}
		else
		{
			program->num_of_moves = program->size_a - program->index_min;
			make_rras(stack_a, 'a', program);
			ft_pb(stack_a, stack_b, program);
		}
		j++;
	}
	sort_3_nums(stack_a, 'a', program);
	ft_pa(stack_a, stack_b, program);
	ft_pa(stack_a, stack_b, program);
}

void	sort_20_nums(int *stack_a, int *stack_b, t_program *program)
{
	int	*arr_sup;
	int	i;
	int	init_size;

	i = 0;
	arr_sup = malloc(sizeof(int) * program->size_a);
	while (i < program->size_a)
	{
		arr_sup[i] = stack_a[i];
		i++;
	}
	sort(arr_sup, program->size_a);
	init_size = program->size_a;
	while (program->size_a != 3)
	{
		if (stack_a[0] <= arr_sup[init_size - 4])
			ft_pb(stack_a, stack_b, program);
		else
			ft_ra_rb(stack_a, 'a', program);
	}
	sort_3_nums(stack_a, 'a', program);
	put_max_in_a(stack_a, stack_b, program);
	free(arr_sup);
}

void	sort_x_nums_support(int *stack_a, int *stack_b, t_program *program)
{
	int	i;

	while (program->size_a)
	{
		i = 0;
		program->to_check = program->arr_sup[program->chunk_size
			* program->chunk - 1];
		program->chunk++;
		if (program->chunk == program->num_of_chunks + 2)
			program->to_check = program->arr_sup[program->init_size - 1];
		while (i < program->chunk_size)
		{
			if (program->size_a <= 0)
				break ;
			if (stack_a[0] <= program->to_check)
			{
				ft_pb(stack_a, stack_b, program);
				i++;
			}
			else
				ft_ra_rb(stack_a, 'a', program);
		}
	}
}

void	sort_x_nums(int *stack_a, int *stack_b, t_program *program)
{
	int	i;

	program->arr_sup = malloc(sizeof(int) * program->size_a);
	i = 0;
	while (i < program->size_a)
	{
		program->arr_sup[i] = stack_a[i];
		i++;
	}
	sort(program->arr_sup, program->size_a);
	program->init_size = program->size_a;
	i = 0;
	if (program->size_a < 250)
		program->num_of_chunks = program->size_a / 20;
	else
		program->num_of_chunks = program->size_a / 50;
	program->chunk_size = program->size_a / program->num_of_chunks;
	program->to_check = program->arr_sup[program->chunk_size - 1];
	program->chunk = 1;
	sort_x_nums_support(stack_a, stack_b, program);
	put_max_in_a(stack_a, stack_b, program);
	free(program->arr_sup);
}
