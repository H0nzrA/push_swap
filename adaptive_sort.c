/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:47:01 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 16:58:45 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	if (!stack_a || !*stack_a)
		error();
	int size = ft_lstsize(*stack_a);
	if (size <= 10)
		minmax_sort(stack_a, stack_b, all_commands);
	if (size <= 360)
		chunk_based_sort(stack_a, stack_b, all_commands);
	if (size > 360)
		radix_lsd_sort(stack_a, stack_b, all_commands);
}
