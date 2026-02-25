/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:49:16 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 13:49:33 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "common.h"
#include "ft_printf/libft/libft.h"

void	start_execution(t_list **stack_a)
{
	t_list	*stack_b;
	char	*command;
	int		eval;

	command = get_next_line(0);
	stack_b = NULL;
	while (command)
	{
		apply_command(command, stack_a, &stack_b);
		free(command);
		command = get_next_line(0);
	}
	eval = evaluation(stack_a, &stack_b);
	if (!eval)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	stack_b = NULL;
}

void	apply_command(char *command, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(command, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(command, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(command, "ss") == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strcmp(command, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(command, "pb") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(command, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(command, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(command, "rr") == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(command, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(command, "rrr") == 0)
		reverse_rotate_ab(stack_a, stack_b);
}
