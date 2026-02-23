/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:47:57 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/23 15:15:02 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static t_list	*ft_cpy(t_list *argv)
{
	t_list	*copy;
    int *var;

	copy = NULL;
	while (argv)
	{
        var = (int *)malloc(sizeof(int));
        *var = *(int *)argv->content;
		ft_lstadd_back(&copy, ft_lstnew(var));
		argv = argv->next;
	}
	return (copy);
}

static t_list	*ft_sort(t_list *argv)
{
	t_list	*copy;
	t_list	*tmpy;
	t_list	*tmp;
	char	*key;

	if (!argv)
		return (NULL);
	copy = ft_cpy(argv);
	tmp = copy;
	while (tmp)
	{
		tmpy = tmp->next;
		while (tmpy)
		{
			if (*(int *)tmp->content > *(int *)tmpy->content)
			{
				key = tmp->content;
				tmp->content = tmpy->content;
				tmpy->content = key;
			}
			tmpy = tmpy->next;
		}
		tmp = tmp->next;
	}
	return (copy);
}

static int	find_max_index(t_list **list)
{
	int		max;
	int		index;
	int		i;
	t_list	*temp;

	temp = *list;
	max = *(int *)temp->content;
	index = 0;
	i = 0;
	while (temp)
	{
		if (max < *(int *)temp->content)
		{
			max = *(int *)temp->content;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

static int	in_lst(t_list **cpy, t_list *find, int t_jump, int size)
{
	int		i;
	t_list	*temp;
	t_list	*cursor;

	cursor = *cpy;
	i = 0;
	if (t_jump == 0)
		temp = *cpy;
	else
	{
		while (i++ < t_jump && cursor)
			cursor = cursor->next;
		if (!cursor)
			return (0);
		temp = cursor;
	}
	i = 0;
	while (i++ < size && temp)
	{
		if (*(int *)temp->content == *(int *)find->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	manage_part(t_list **list, char **all_commands)
{
	int	index;
	int	size;
	int	part;

	index = find_max_index(list);
	size = ft_lstsize(*list);
	part = size / 2;
	if (index <= part)
	{
		while (index > 0)
		{
			rotate(list);
			take_command(all_commands, "rb");
			index = find_max_index(list);
		}
		return ;
	}
	while (index < size - 1)
	{
		reverse_rotate(list);
		take_command(all_commands, "rrb");
		index = find_max_index(list);
	}
	reverse_rotate(list);
	take_command(all_commands, "rrb");
}

static int	find_square_root(int n)
{
	int	i;

	i = 0;
	while (i < n / 2)
	{
		if (i * i == n)
			return (i);
		if (i * i < n && (i + 1) * (i + 1) > n)
			return (i);
		i++;
	}
	return (0);
}

static void	manage_cmp_chunk(int *sq, int *count, int size, int *i)
{
	if (*sq == 0)
		*sq = 1;
	else
	{
		if (*count == (size / *sq))
		{
			*i = *i + (size / *sq);
			*count = 0;
		}
	}
}

static void	shortcut(t_list **stack_a, t_list **stack_b, char **com, int mode)
{
	if (mode == 1)
	{
		push(stack_a, stack_b);
		take_command(com, "pb");
	}
	if (mode == 2)
	{
		rotate(stack_a);
		take_command(com, "ra");
	}
}

static void	cmp_chunk(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	int		size;
	int		i;
	int		count;
	int		sq;
	t_list	*str;

	i = 0;
	count = 0;
	str = ft_sort(*stack_a);
	size = ft_lstsize(*stack_a);
	sq = find_square_root(size);
	while (*stack_a)
	{
		manage_cmp_chunk(&sq, &count, size, &i);
		if (in_lst(&str, *stack_a, i, (size / sq)) && count < (size / sq))
		{
			shortcut(stack_a, stack_b, all_commands, 1);
			count++;
		}
		else
			shortcut(stack_a, stack_b, all_commands, 2);
		manage_cmp_chunk(&sq, &count, size, &i);
	}
}

void	chunk_based_sort(t_list **stack_a, t_list **stack_b,
		char **all_commands)
{
	cmp_chunk(stack_a, stack_b, all_commands);
	while (*stack_b)
	{
		manage_part(stack_b, all_commands);
		push(stack_b, stack_a);
		take_command(all_commands, "pa");
	}
}
