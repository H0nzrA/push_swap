/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:15 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/17 13:51:37 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)strat;
	list = NULL;
	while (i < argc)
	{
		parsing(&list, argv[i]);
		i++;
	}

	t_list *element = NULL;
	t_list *temp;

	temp = element;
	ft_printf("Avant push:\n");
	while (temp)
	{
		ft_printf("%s | ", (char *)temp->content);
		temp = temp->next;
	}

	push(&list, &element);
	push(&list, &element);
	push(&list, &element);
	push(&list, &element);
	ft_printf("\n---------------------\n");
	temp = element;
	ft_printf("Apres push:\n");
	while (temp)
	{
		ft_printf("%s | ", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, free);
	ft_lstclear(&element, free);
	return (0);
}
