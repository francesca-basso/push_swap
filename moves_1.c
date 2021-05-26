#include "push_swap.h"

void	ft_sa_sb(int *stack, char what_stack, t_program *program)
{
	int	size;
	int	temp;

	program->moves++;
	if (what_stack == 'a')
	{
		ft_putstr("sa\n");
		size = program->size_a;
	}
	else
	{
		ft_putstr("sb\n");
		size = program->size_b;
	}
	if (size < 3)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ft_ss(int *stack_a, int *stack_b, t_program *program)
{
	ft_sa_sb(stack_a, 'a', program);
	ft_sa_sb(stack_b, 'b', program);
	ft_putstr("ss\n");
	program->moves++;
}

void	ft_pb(int *stack_a, int *stack_b, t_program *program)
{
	int	i;
	int	to_swap;

	to_swap = stack_a[0];
	program->moves++;
	i = 0;
	while (i < (program->size_a - 1))
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	program->size_a--;
	program->size_b++;
	i = program->size_b - 1;
	while (i >= 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = to_swap;
	ft_putstr("pb\n");
}

void	ft_pa(int *stack_a, int *stack_b, t_program *program)
{
	int	i;
	int	to_swap;

	to_swap = stack_b[0];
	program->moves++;
	i = 0;
	while (i < (program->size_b - 1))
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	program->size_b--;
	program->size_a++;
	i = program->size_a - 1;
	while (i >= 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = to_swap;
	ft_putstr("pa\n");
}

void	ft_ra_rb(int *stack, char what_stack, t_program *program)
{
	int	i;
	int	temp;
	int	size;

	program->moves++;
	if (what_stack == 'a')
	{
		ft_putstr("ra\n");
		size = program->size_a;
	}
	else
	{
		ft_putstr("rb\n");
		size = program->size_b;
	}
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}
