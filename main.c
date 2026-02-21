/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:15 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/21 17:17:41 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_strat	strat;
	t_list	*list;

	if (argc < 2)
		error();
	list = NULL;
	parsing(&list, &argv[1], &strat);
	if (ft_lstsize(list) < 2)
		return (0);
	start_algo(&list, strat);
	ft_lstclear(&list, free);
	return (0);
}
