/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:48:45 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/17 13:45:52 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rotate(t_list **list)
{
	t_list	*temp;

	temp = *list;
	*list = temp->next;
	temp->next = NULL;
	ft_lstadd_back(list, temp);
}
