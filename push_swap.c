/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:07:41 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 16:54:14 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
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
	t_list	*stack_b;
	char	*all_commands;

	stack_b = NULL;
	all_commands = NULL;
	if (compute_disorder(list) == 0)
		return ;
	if (strategy == SIMPLE)
		minmax_sort(list, &stack_b, &all_commands);
	ft_printf("%s", all_commands);
	free(all_commands);
	ft_lstclear(&stack_b, free);
}
