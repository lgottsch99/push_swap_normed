/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:32:25 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 19:00:01 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *info, int pos, t_list *a)
{
	info->size_a = ft_lstsize(a);
	info->size_b = 0;
	info->rot_a = -1;
	info->rot_b = -1;
	info->steps_a = 0;
	info->steps_b = 0;
	info->rr = 0;
	info->rrr = 0;
	info->total_steps = 0;
	info->pos_a = pos;
}

int	set_mid_b(int size, t_list *lst)
{
	int	mid;

	if (size <= 3)
		mid = 1;
	else
		mid = get_mid_pos(lst);
	return (mid);
}

t_list	*set_tmp(t_list *tmp, t_list *b)
{
	if (tmp->next)
		tmp = tmp->next;
	else
		tmp = b;
	return (tmp);
}

int	get_pos_in_b(t_list	*node_a, t_list	*b, t_list	*max)
{
	int		pos;
	t_list	*tmp;
	t_list	*next;

	pos = 0;
	tmp = max;
	if (tmp->next)
		next = tmp->next;
	else
		next = b;
	while (pos == 0)
	{
		if ((*(int *)tmp->content > *(int *)node_a->content)
			&& (*(int *)next->content < *(int *)node_a->content))
			pos = get_position(b, next);
		else
		{
			tmp = set_tmp(tmp, b);
			if (next->next)
				next = next->next;
			else
				next = b;
		}
	}
	return (pos);
}

void	rotation_a(int pos_a, int size_a, t_info *info, t_list *a)
{
	int	mid;
	int	steps;

	steps = 0;
	mid = get_mid_pos(a);
	if (pos_a <= mid)
	{
		info->rot_a = 1;
		while (pos_a > 1)
		{
			pos_a--;
			steps++;
		}
	}
	if (pos_a > mid)
	{
		info->rot_a = 0;
		while (pos_a < (size_a + 1))
		{
			pos_a++;
			steps++;
		}
	}
	info->steps_a = steps;
}
