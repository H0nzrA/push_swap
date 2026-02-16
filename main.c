/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:15 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/16 17:48:04 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_strat	strat;
	t_list	*list;
	int		i;
	t_list	*temp;

	if (argc < 2)
		error();
	strat = ADAPTIVE;
	i = 1;
	if (is_strategy(argv[i]))
		strat = get_strategy(argv[i++]);
	(void)strat;
	list = NULL;
	while (i < argc)
	{
		parsing(&list, argv[i]);
		i++;
	}
	temp = list;
	while (temp)
	{
		ft_printf("%s\n", temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, free);
	return (0);
}
