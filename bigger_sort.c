/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:26:11 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 18:58:35 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_push(t_stack *stacks, t_info *cheapest)
{
	while (cheapest->steps_b > 0)
	{
		if (cheapest->rot_b == 1)
			stacks = rb(stacks);
		else if (cheapest->rot_b == 0)
			stacks = rrb(stacks);
		cheapest->steps_b--;
	}
}

void	do_push(t_stack *stacks, t_info *cheapest)
{
	if (cheapest->rr > 0 || cheapest->rrr > 0)
	{
		while (cheapest->rr > 0)
		{
			stacks = rr(stacks);
			cheapest->rr--;
		}
		while (cheapest->rrr > 0)
		{
			stacks = rrr(stacks);
			cheapest->rrr--;
		}
	}
	while (cheapest->steps_a > 0)
	{
		if (cheapest->rot_a == 1)
			stacks = ra(stacks);
		else if (cheapest->rot_a == 0)
			stacks = rra(stacks);
		cheapest->steps_a--;
	}
	cont_push(stacks, cheapest);
	stacks = pb(stacks);
}

t_info	*rot_check(t_info *info)
{
	if (info->rot_a == info->rot_b)
	{
		if (info->steps_a > 0 && info->steps_b > 0)
		{
			while (info->steps_a > 0 && info->steps_b > 0)
			{
				if (info->rot_a == 1)
					info->rr += 1;
				else if (info->rot_a == 0)
					info->rrr += 1;
				info->steps_a--;
				info->steps_b--;
			}
		}
	}
	info->total_steps = 1 + info->steps_a
		+ info->steps_b + info->rr + info->rrr;
	return (info);
}

void	update(int pos_a, t_info *info, t_info *cheapest)
{
	if (pos_a == 1 || info->total_steps < cheapest->total_steps)
	{
		cheapest->pos_a = pos_a;
		cheapest->rot_a = info->rot_a;
		cheapest->rot_b = info->rot_b;
		cheapest->steps_a = info->steps_a;
		cheapest->steps_b = info->steps_b;
		cheapest->rr = info->rr;
		cheapest->rrr = info->rrr;
		cheapest->total_steps = info->total_steps;
	}
}

t_stack	*do_bigger_sort(t_stack	*stacks)
{
	int		pos_a;
	t_list	*node;
	t_info	info;
	t_info	cheapest;

	pos_a = 1;
	init_info(&info, pos_a, stacks->a);
	init_info (&cheapest, 0, stacks->a);
	info.size_a = ft_lstsize(stacks->a);
	while (pos_a <= info.size_a)
	{
		init_info(&info, pos_a, stacks->a);
		node = get_node_at_pos(stacks->a, pos_a);
		rotation_a(pos_a, info.size_a, &info, stacks->a);
		info.steps_b = rotation_b(node, stacks->b, &info);
		info = *rot_check(&info);
		update(pos_a, &info, &cheapest);
		pos_a++;
	}
	do_push(stacks, &cheapest);
	return (stacks);
}
