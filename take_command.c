/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:52:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 16:53:17 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	take_command(char **all_commands, char *command)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(*all_commands, command);
	res = ft_strjoin(tmp, "\n");
	free(tmp);
	free(*all_commands);
	*all_commands = res;
}
