/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:09:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 16:51:35 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static int	find_min_index(t_list **list)
{
	int		min;
	int		index;
	int		i;
	t_list	*temp;

	temp = *list;
	min = ft_atoi(temp->content);
	index = 0;
	i = 0;
	while (temp)
	{
		if (min > ft_atoi(temp->content))
		{
			min = ft_atoi(temp->content);
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

static void	do_part(t_list **list, char **all_commands)
{
	int	index;
	int	size;
	int	part;

	index = find_min_index(list);
	size = ft_lstsize(*list);
	part = size / 2;
	if (index <= part)
	{
		while (index > 0)
		{
			rotate(list);
			take_command(all_commands, "ra");
			index = find_min_index(list);
		}
		return ;
	}
	while (index < size - 1)
	{
		reverse_rotate(list);
		take_command(all_commands, "rra");
		index = find_min_index(list);
	}
	reverse_rotate(list);
	take_command(all_commands, "rra");
}

void	minmax_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	*stack_b = NULL;
	while (*stack_a)
	{
		do_part(stack_a, all_commands);
		push(stack_a, stack_b);
		take_command(all_commands, "pb");
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		take_command(all_commands, "pa");
	}
}
