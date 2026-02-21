/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:42:31 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/21 17:45:24 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_benchmark(const char *str)
{
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	return (0);
}

int	have_bench(const char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (is_benchmark(argv[i]))
			return (1);
	return (0);
}

void	print_command(const char *all_commands, int *bench)
{
	if (!*bench)
		ft_printf("%s", all_commands);
}
