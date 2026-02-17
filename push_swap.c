/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:07:41 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/17 17:35:18 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_list **list, char *str)
{
	t_list	*l;
	t_list	*temp;

	if (!is_valid_digit(str))
	{
		ft_lstclear(list, free);
		error();
	}
	temp = *list;
	while (temp)
	{
		if (ft_atoi((char *)temp->content) == ft_atoi((char *)str))
		{
			ft_lstclear(list, free);
			error();
		}
		temp = temp->next;
	}
	l = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(list, l);
}

void	start_algo(t_list **list, t_strat strategy)
{
	t_list *B;

	B = NULL;
	if (strategy == SIMPLE)
		minmax_sort(list, &B);
	ft_lstclear(&B, free);
}
