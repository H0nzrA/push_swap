/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:10:34 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/16 09:22:03 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error()
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	evaluate_arguments(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		int	temp;

		temp = ft_atoi(argv[i]);
		if (temp)
	}
	return (1);
}
