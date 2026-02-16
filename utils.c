/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:45:49 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/16 13:34:10 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	size_t	i;
	size_t	len;
	long	val;
	int		sign;

	i = 0;
	val = 0;
	len = ft_strlen(str);
	sign = 1;
	while (i < len && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (i < len && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < len && ft_isdigit(str[i]))
	{
		val *= 10;
		val += str[i] - '0';
		i++;
	}
	return (val * sign);
}

int	is_valid_digit(const char *str)
{
	int		i;
	long	val;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	val = ft_atoi_long(str);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_strategy(const char *str)
{
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	return (0);
}

t_strat	get_strategy(const char *str)
{
	if (ft_strcmp(str, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcmp(str, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}
