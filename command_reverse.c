/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:55:09 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/17 14:03:40 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	reverse_rotate(t_list **list)
{
	t_list *temp;
	t_list *temp2;
	t_list *key;

	temp = ft_lstlast(*list);
	key = *list;
	while (key)
	{
		temp2 = key;
		key = key->next;
		if (key && key->next)
	}
}

