/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:29 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 09:02:59 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}		t_strat;

void	start_algo(t_list **list, t_strat strategy, int bench);
int		compute_disorder(t_list **list);

void	parsing(t_list **list, char **argv, t_strat *strat, int *bench);
void	error(void);

int		is_valid_digit(const char *str);
int		is_strategy(const char *str);
int		have_bench(const char **argv);
t_strat	get_strategy(const char *str);

long	ft_atoi_long(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

void	swap(t_list **list);
void	swap_ab(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);

void	rotate_ab(t_list **a, t_list **b);
void	rotate(t_list **list);

void	reverse_rotate(t_list **list);
void	reverse_rotate_ab(t_list **a, t_list **b);

void	take_command(char **all_commands, char *command);
void	print_command(const char *all_commands, int bench,
			int compute_disorder, t_strat strat);

void	minmax_sort(t_list **stack_a, t_list **stack_b, char **all_commands);
void	radix_lsd_sort(t_list **stack_a, t_list **stack_b, char **all_commands);

typedef struct s_ops
{
	int	ra;
	int	rb;
	int	rr;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	total;
}		t_ops;

void	init_ops_bench(t_ops *ops);
int		is_benchmark(const char *str);
void	print_bench(const char *all_commands, int compute_disorder, t_strat strat);
void	parse_command_bench(char *all_command, t_ops *ops);

#endif
