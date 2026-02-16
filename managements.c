/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:10:34 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/16 12:48:08 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	evaluate_arguments(int argc, char **argv)
{
	int		i;
	int		have_strat;
	t_strat	strategy;

	i = 1;
	have_strat = 0;
	if (is_strategy(argv[i]))
	{
		strategy = get_strategy(argv[i]);
		i++;
	}
	while (i < argc)
	{
		if (!is_valid_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
