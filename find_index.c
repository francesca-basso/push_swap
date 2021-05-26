#include "push_swap.h"

int	get_index_max(int *stack, char what_stack, t_program *program)
{
	int	size;
	int	init;
	int	i;
	int	to_return;

	if (what_stack == 'a')
		size = program->size_a;
	else
		size = program->size_b;
	i = 0;
	init = stack[0];
	while (i < size)
	{
		if (stack[i] > init)
		{
			init = stack[i];
			to_return = i;
		}
		i++;
	}
	return (to_return);
}

int	get_index_min(int *stack, int size)
{
	int	init;
	int	i;
	int	to_return;

	if (size <= 0)
		return (0);
	i = 0;
	init = stack[0];
	to_return = 0;
	while (i < size)
	{
		if (stack[i] < init)
		{
			init = stack[i];
			to_return = i;
		}
		i++;
	}
	return (to_return);
}

void	swap (int *arr, int index_1, int index_2)
{
	int	temp;

	temp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;
}

void	sort(int arr[], int size)
{
	int	i;
	int	indice_min;
	int	j;

	if (size < 0)
		return ;
	i = 0;
	while (i < (size - 1))
	{
		indice_min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[indice_min])
				indice_min = j;
			j++;
		}
		swap(arr, indice_min, i);
		i++;
	}
}

int	is_array_sorted(int s[], int n)
{
	int	a;
	int	i;

	i = 0;
	a = 1;
	while (a == 1 && i < n - 1)
	{
		if (s[i] > s[i + 1])
			a = 0;
		i++;
	}
	if (a == 1)
		return (1);
	else
		return (0);
}
