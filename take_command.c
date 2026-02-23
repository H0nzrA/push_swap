/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:52:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 10:08:53 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	printstr_stderr(const char *str)
{
	ft_putstr_fd((char *)str, 2);
}

void	take_command(char **all_commands, char *command)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(*all_commands, command);
	res = ft_strjoin(tmp, "\n");
	free(tmp);
	free(*all_commands);
	*all_commands = res;
}

void	print_command(const char *all_commands, int bench, int compute_disorder,
		t_strat strat)
{
	char	*res;

	ft_printf("%s", all_commands);
	if (bench)
	{
		res = get_bench(all_commands, compute_disorder, strat);
		printstr_stderr(res);
		free(res);
	}
}
