/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:47:01 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 14:31:44 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	int	disorder;

	if (!stack_a || !*stack_a)
		error();
	disorder = compute_disorder(stack_a);
	if (disorder < 2000)
		minmax_sort(stack_a, stack_b, all_commands);
	if (2000 <= disorder && disorder < 5000)
		chunk_based_sort(stack_a, stack_b, all_commands);
	if (disorder >= 5000)
		radix_lsd_sort(stack_a, stack_b, all_commands);
}

void	for_bench_adaptive(char **buffer, int disorder)
{
	if (disorder < 2000)
		buff_add(buffer, "Adaptive / O(n^2)\n");
	if (2000 <= disorder && disorder < 5000)
		buff_add(buffer, "Adaptive / O(n√n)\n");
	if (disorder >= 5000)
		buff_add(buffer, "Adaptive / O(nlogn)\n");
}
