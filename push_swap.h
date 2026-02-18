/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:29 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/18 00:34:25 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}		t_strat;

void	start_algo(t_list **list, t_strat strategy);

void	parsing(t_list **list, char *str);
void	error(void);

int		is_valid_digit(const char *str);
int		is_strategy(const char *str);
t_strat	get_strategy(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

void	swap(t_list **list);
void	swap_ab(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);

void	rotate_ab(t_list **a, t_list **b);
void	rotate(t_list **list);

void	reverse_rotate(t_list **list);
void	reverse_rotate_ab(t_list **a, t_list **b);

void	minmax_sort(t_list **A);

#endif
