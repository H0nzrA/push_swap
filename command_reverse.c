/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:55:09 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/17 14:11:25 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	reverse_rotate(t_list **list)
{
	t_list *last;
	t_list	*temp;

	last = ft_lstlast(*list);
	temp = *list;
	while (temp)
	{
		if (temp->next == last)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	last->next = *list;
	*list = last;
}

