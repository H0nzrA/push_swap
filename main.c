/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:15 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 14:56:23 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_strat	strat;
	t_list	*list;
	int		i;

	if (argc < 2)
		error();
	strat = ADAPTIVE;
	i = 1;
	if (is_strategy(argv[i]))
		strat = get_strategy(argv[i++]);
	list = NULL;
	while (i < argc)
	{
		parsing(&list, argv[i]);
		i++;
	}
	if (ft_lstsize(list) < 2)
		return (0);
	start_algo(&list, strat);
	ft_lstclear(&list, free);
	return (0);
}
