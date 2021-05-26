#include "push_swap.h"

void	no_way(t_program *program, int argc, char **argv)
{
	program->i = 1;
	while (program->i < argc)
	{
		program->stack_a[program->i - 1] = ft_atoi(argv[program->i]);
		if (ft_atoi(argv[program->i]) == 0
			&& ft_strncmp(argv[program->i], "0", 1) != 0)
			exit_program();
		program->size_a++;
		program->i++;
	}
}

void	init(t_program *program, int argc, char **argv)
{
	program->size_a = 0;
	program->size_b = 0;
	program->stack_a = (int *)malloc(sizeof(int)
			* (program->num_to_alloc - 1));
	program->stack_b = (int *)malloc(sizeof(int)
			* (program->num_to_alloc - 1));
	if (program->argv_arg == 1)
		no_way(program, argc, argv);
	else
	{
		program->i = 0;
		while (program->i < program->num_to_alloc)
		{
			program->stack_a[program->i] = ft_atoi(
					program->vars[program->i]);
			program->size_a++;
			program->i++;
		}
	}
}

void	main_support(t_program *program)
{
	if (program->num_to_alloc == 2)
	{
		if (program->stack_a[0] > program->stack_a[1])
			ft_sa_sb(program->stack_a, 'a', program);
	}
	else if (program->num_to_alloc == 3)
		sort_3_nums(program->stack_a, 'a', program);
	else if (program->num_to_alloc == 5)
		sort_5_nums(program->stack_a, program->stack_b, program);
	else if (program->num_to_alloc < 20)
		sort_20_nums(program->stack_a, program->stack_b, program);
	else
		sort_x_nums(program->stack_a, program->stack_b, program);
}

void	start_main(t_program *program, int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		program->num_to_alloc = 0;
		i = 0;
		check_valid_string(argv[1]);
		program->vars = ft_split(argv[1], ' ');
		while (program->vars[program->num_to_alloc])
			program->num_to_alloc++;
		program->argv_arg = 0;
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			check_valid_string(argv[i]);
			i++;
		}
		program->argv_arg = 1;
		program->num_to_alloc = argc - 1;
	}
}

int	main(int argc, char **argv)
{
	t_program	program;

	start_main(&program, argc, argv);
	init(&program, argc, argv);
	if (is_array_sorted(program.stack_a, program.size_a) == 1)
	{
		free_program(&program);
		exit(1);
	}
	find_duplicates(program.stack_a, program.size_a);
	main_support(&program);
	free_program(&program);
	return (0);
}
