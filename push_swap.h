#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_program
{
	int			size_a;
	int			size_b;
	int			moves;
	int			num_of_nums;
	int			index_min;
	int			num_of_moves;
	int			index_max;
	int			chunk_size;
	int			num_of_chunks;
	int			*arr_sup;
	int			init_size;
	int			to_check;
	int			chunk;
	int			argv_arg;
	char		**vars;
	int			num_to_alloc;
	int			i;
	int			*stack_a;
	int			*stack_b;
}				t_program;

int		get_next_line(int fd, char **line);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		is_space(char c);
void	ft_sa_sb(int *stack, char what_stack, t_program *program);
void	ft_ss(int *stack_a, int *stack_b, t_program *program);
void	ft_pb(int *stack_a, int *stack_b, t_program *program);
void	ft_pa(int *stack_a, int *stack_b, t_program *program);
void	ft_ra_rb(int *stack, char what_stack, t_program *program);
void	ft_rr(int *stack_a, int *stack_b, t_program *program);
void	ft_rra_rrb(int *stack, char what_stack, t_program *program);
void	ft_rrr(int *stack_a, int *stack_b, t_program *program);
void	print_stack(int *stack, int size);
int		ft_strlen(char *s);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
int		get_index_min(int *stack, int size);
int		get_index_max(int *stack, char what_stack, t_program *program);
void	sort(int arr[], int size);
int		is_array_sorted(int s[], int n);
void	exit_program(void);
void	find_duplicates(int *stack_a, int size);
void	check_valid_string(char *s);
void	sort_3_nums(int *stack_a, char what_stack, t_program *program);
void	sort_5_nums(int *stack_a, int *stack_b, t_program *program);
void	sort_x_nums(int *stack_a, int *stack_b, t_program *program);
void	sort_20_nums(int *stack_a, int *stack_b, t_program *program);
void	sort(int arr[], int size);
void	make_ras(int *stack, char what_stack, t_program *program);
void	make_rras(int *stack, char what_stack, t_program *program);
void	put_max_in_a(int *stack_a, int *stack_b, t_program *program);
void	free_program(t_program *program);

#endif
