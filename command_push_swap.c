/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:33 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/17 13:48:38 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

void	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	push(t_list **a, t_list **b)
{
	t_list	*first_a;
	t_list	*next_a;

	first_a = *a;
	next_a = first_a->next;
	ft_lstadd_front(b, first_a);
	*a = next_a;
}
