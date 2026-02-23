/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:42:31 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 09:25:59 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	printstr_stderr(const char *str)
{
	ft_putstr_fd((char *)str, 2);
}

static void	printnbr_stderr(int num)
{
	ft_putnbr_fd(num, 2);
}

static void	print_bench_ops(t_ops *ops)
{
	printstr_stderr("[bench]");
	printstr_stderr(" sa: ");
	printnbr_stderr(ops->sa);
	printstr_stderr(" sb: ");
	printnbr_stderr(ops->sb);
	printstr_stderr(" ss: ");
	printnbr_stderr(ops->ss);
	printstr_stderr(" pa: ");
	printnbr_stderr(ops->pa);
	printstr_stderr(" pb: ");
	printnbr_stderr(ops->pb);
	printstr_stderr("\n");
	printstr_stderr("[bench]");
	printstr_stderr(" ra: ");
	printnbr_stderr(ops->ra);
	printstr_stderr(" rb: ");
	printnbr_stderr(ops->rb);
	printstr_stderr(" rr: ");
	printnbr_stderr(ops->rr);
	printstr_stderr(" rra: ");
	printnbr_stderr(ops->rra);
	printstr_stderr(" rrb: ");
	printnbr_stderr(ops->rrb);
	printstr_stderr(" rrr: ");
	printnbr_stderr(ops->rrr);
}

static void	print_bench_info(t_ops *ops, int disorder, t_strat strat)
{
	printstr_stderr("[bench] disorder:\t");
	printnbr_stderr(disorder);
	printstr_stderr("\n");
	printstr_stderr("[bench] strategy:\t");
	if (strat == SIMPLE)
		printstr_stderr("Simple / O(n^2)");
	else if (strat == MEDIUM)
		printstr_stderr("Medium / <not implemented>");
	else if (strat == COMPLEX)
		printstr_stderr("Complex / O(n log n)");
	else if (strat == ADAPTIVE)
		printstr_stderr("Adaptive / <not implemented>");
	printstr_stderr("\n");
	printstr_stderr("[bench] total_ops:\t");
	printnbr_stderr(ops->total);
	printstr_stderr("\n");
	print_bench_ops(ops);
	printstr_stderr("\n");
}

void	print_bench(const char *all_commands, int disorder, t_strat strat)
{
	t_ops	ops;

	if (!all_commands)
		return ;
	init_ops_bench(&ops);
	parse_command_bench((char *)all_commands, &ops);
	print_bench_info(&ops, disorder, strat);
}
