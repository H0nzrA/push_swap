/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:56:33 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 11:03:21 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
		error();
	list = NULL;
	parsing(&list, &argv[1]);
	if (ft_lstsize(list) < 2)
		return (0);
	ft_lstclear(&list, free);
	return (0);
}
