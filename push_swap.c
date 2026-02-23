/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:07:41 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 09:02:18 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	start_algo(t_list **list, t_strat strategy, int bench)
{
	t_list	*stack_b;
	char	*all_commands;
	int disorder;

	stack_b = NULL;
	all_commands = NULL;
	disorder = compute_disorder(list);
	if (disorder == 0)
		return ;
	if (strategy == SIMPLE)
		minmax_sort(list, &stack_b, &all_commands);
	if (strategy == COMPLEX)
		radix_lsd_sort(list, &stack_b, &all_commands);
	print_command(all_commands, bench, disorder, strategy);
	free(all_commands);
	ft_lstclear(&stack_b, free);
}
