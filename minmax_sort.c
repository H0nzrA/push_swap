/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:09:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/17 17:44:09 by trakotoz         ###   ########.fr       */
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
	if (index > 0)
	{
		while (index > 0)
		{
			rotate(list);
			index = find_min_index(list);
		}
	}
	else
	{
		while (index < size)
		{
			reverse_rotate(list);
			index = find_min_index(list);
		}
	}
}

void	minmax_sort(t_list **A, t_list **B)
{
	// int	index;
	//
	// t_list *temp;
	//
	// temp = *A;
	// while (temp)
	// {
	// 	index = find_min_index(&temp);
	// 	do_part(&temp);
	// 	push(&temp, B);
	// }
	// temp = *B;
	// while (temp)
	// {
	// 	ft_printf("%s | ", temp->content);
	// 	temp = temp->next;
	// }
}
