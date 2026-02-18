/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:09:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 11:04:25 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
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
static void	do_part(t_list **list)
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
			ft_printf("ra\n");
			index = find_min_index(list);
		}
	}
	else
	{
		while (index < size - 1)
		{
			reverse_rotate(list);
			ft_printf("rra\n");
			index = find_min_index(list);
		}
		reverse_rotate(list);
		ft_printf("rra\n");
	}
}

void	minmax_sort(t_list **stack_a, t_list **stack_b)
{
	*stack_b = NULL;
	while (*stack_a)
	{
		do_part(stack_a);
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
