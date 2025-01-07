/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:51:47 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 19:00:30 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	go_on(int pos, int steps)
{
	while (pos != 1)
	{
		pos--;
		steps++;
	}
	return (steps);
}

int	calc_steps(t_list *lst, int pos, int *rot)
{
	int	steps;
	int	mid;
	int	size;

	size = ft_lstsize(lst);
	mid = set_mid_b(size, lst);
	steps = 0;
	if (pos <= mid)
	{
		*rot = 1;
		steps = go_on(pos, steps);
	}
	else if (pos > mid)
	{
		*rot = 0;
		while (pos != (size + 1))
		{
			pos++;
			steps++;
		}
	}
	return (steps);
}

int	go_on_last(int pos, int steps)
{
	while (pos > 0)
	{
		pos--;
		steps++;
	}
	return (steps);
}

int	calc_steps_last(t_list *lst, int pos, int *rot)
{
	int	steps;
	int	mid;
	int	size;

	size = ft_lstsize(lst);
	mid = set_mid_b(size, lst);
	steps = 0;
	if (pos < mid)
	{
		*rot = 1;
		steps = go_on_last(pos, steps);
	}
	else if (pos >= mid)
	{
		*rot = 0;
		while (pos < size)
		{
			pos++;
			steps++;
		}
	}
	return (steps);
}

int	rotation_b(t_list *node_a, t_list *b, t_info *info)
{
	t_list	*min;
	t_list	*max;
	int		pos_in_b;

	info->steps_b = 0;
	info->size_b = ft_lstsize(b);
	min = get_min(b);
	max = get_max(b);
	if (*(int *)node_a->content > *(int *)max->content
		|| *(int *)node_a->content < *(int *)min->content)
	{
		if (get_position(b, max) > 1)
			info->steps_b = calc_steps(b, get_position(b, max), &info->rot_b);
		else
			info->steps_b = 0;
	}
	else
	{
		pos_in_b = get_pos_in_b(node_a, b, max);
		if (pos_in_b > 1)
			info->steps_b = calc_steps(b, pos_in_b, &info->rot_b);
		else
			info->steps_b = 0;
	}
	return (info->steps_b);
}
