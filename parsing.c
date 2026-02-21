/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:31:37 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/21 15:45:49 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
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

static int	have_duplicate(t_list **list, int num)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (*(int *)(temp->content) == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	get_argument(t_list **list, char **res)
{
	t_list	*temp;
	int		i;
	int		num;
	int		*val;

	i = 0;
	while (res[i])
	{
		temp = *list;
		num = ft_atoi(res[i]);
		if (have_duplicate(list, num))
		{
			ft_lstclear(list, free);
			error();
		}
		val = (int *)malloc(sizeof(int));
		if (!val)
		{
			ft_lstclear(list, free);
			return ;
		}
		*val = num;
		ft_lstadd_back(list, ft_lstnew(val));
		i++;
	}
}

void	parsing(t_list **list, char *str)
{
	char	**res;
	int		i;

	res = parse_arguments(str);
	if (!is_valid_arguments(res))
	{
		i = 0;
		while (res[i])
			free(res[i++]);
		free(res);
		ft_lstclear(list, free);
		error();
	}
	get_argument(list, res);
	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}
