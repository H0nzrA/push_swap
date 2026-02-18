/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:31:37 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 17:35:05 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_arguments(char *str)
{
	char	**res;

	res = ft_split(str, ' ');
	if (!res)
		return (NULL);
	return (res);
}

static int	is_valid_arguments(char **res)
{
	int	i;

	if (!res)
		return (0);
	i = 0;
	while (res[i] != NULL)
	{
		if (!is_valid_digit(res[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

static void	get_argument(t_list **list, char **res)
{
	t_list	*l;
	t_list	*temp;
	int		i;

	i = 0;
	while (res[i])
	{
		temp = *list;
		while (temp)
		{
			if (ft_atoi((char *)temp->content) == ft_atoi((char *)res[i]))
			{
				ft_lstclear(list, free);
				error();
			}
			temp = temp->next;
		}
		l = ft_lstnew(ft_strdup(res[i]));
		ft_lstadd_back(list, l);
		i++;
	}
}

void	parsing(t_list **list, char *str)
{
	char	**res;

	res = parse_arguments(str);
	if (!is_valid_arguments(res))
	{
		free_split(res);
		ft_lstclear(list, free);
		error();
	}
	get_argument(list, res);
	free_split(res);
}
