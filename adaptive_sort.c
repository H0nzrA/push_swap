/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:47:01 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 17:44:35 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
    int disorder;

	if (!stack_a || !*stack_a)
		error();
    disorder = compute_disorder(stack_a);
	if (disorder < 200)
		minmax_sort(stack_a, stack_b, all_commands);
	if (200 <= disorder && disorder < 500)
		chunk_based_sort(stack_a, stack_b, all_commands);
	if (disorder >= 500)
		radix_lsd_sort(stack_a, stack_b, all_commands);
}
