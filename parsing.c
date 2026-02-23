/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:31:37 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 10:15:53 by trakotoz         ###   ########.fr       */
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
		if (!is_valid_digit(res[i]) && !is_strategy(res[i])
			&& !is_benchmark(res[i]))
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

static void	get_argument(t_list **list, char **res, t_strat *strat)
{
	int	i;
	int	*val;
	int	have_strat;

	i = -1;
	have_strat = 0;
	while (res[++i])
	{
		if (is_benchmark(res[i]))
			continue ;
		if (is_strategy(res[i]) && !have_strat)
		{
			*strat = get_strategy(res[i]);
			have_strat = 1;
			continue ;
		}
		val = (int *)malloc(sizeof(int));
		if (!val || have_duplicate(list, ft_atoi(res[i])))
			(free(val), ft_lstclear(list, free), error());
		*val = ft_atoi(res[i]);
		ft_lstadd_back(list, ft_lstnew(val));
	}
}

void	parsing(t_list **list, char **argv, t_strat *strat, int *bench)
{
	char	**res;
	int		i;
	int		k;

	k = -1;
	while (argv[++k] != NULL)
	{
		res = parse_arguments(argv[k]);
		if (!is_valid_arguments(res))
		{
			i = 0;
			while (res[i])
				free(res[i++]);
			free(res);
			ft_lstclear(list, free);
			error();
		}
		if (have_bench((const char **)res))
			*bench = 1;
		get_argument(list, res, strat);
		i = 0;
		while (res[i])
			free(res[i++]);
		free(res);
	}
}
