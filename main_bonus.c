/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:56:33 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 14:31:44 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
		error();
	list = NULL;
	parsing(&list, &argv[1]);
	if (ft_lstsize(list) < 2)
	{
		ft_lstclear(&list, free);
		ft_printf("OK\n");
		return (0);
	}
	start_execution(&list);
	return (0);
}
