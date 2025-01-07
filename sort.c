/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:21:04 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:11:35 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_input_sorted2(t_list *tmp, int i, int y, int size)
{
	while (tmp && size > 1 && i < size)
	{
		i++;
		if (tmp->next)
		{
			if (*(int *)tmp->content < *(int *)tmp->next->content)
			{
				y++;
				if (tmp->next)
					tmp = tmp->next;
				else
					break ;
			}
		}
		else
			break ;
	}
	return (y);
}

int	is_input_sorted(t_stack *stacks)
{
	int		size;
	int		i;
	t_list	*tmp;
	int		y;

	i = 0;
	y = 0;
	size = ft_lstsize(stacks->a);
	tmp = stacks->a;
	y = is_input_sorted2(tmp, i, y, size);
	if (y == size - 1)
		return (1);
	return (0);
}

t_stack	*sort_2(t_stack *stacks)
{
	t_list	*tmp;

	tmp = stacks->a;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		stacks = sa(stacks);
	return (stacks);
}

t_stack	*final_rot_b(t_stack *stacks)
{
	t_list	*max;
	int		maxpos;
	int		rot;
	int		steps;

	rot = -1;
	steps = 0;
	max = get_max(stacks->b);
	maxpos = get_position(stacks->b, max);
	if (maxpos != 1)
		steps = calc_steps(stacks->b, maxpos, &rot);
	while (steps > 0)
	{
		if (rot == 1)
			stacks = rb(stacks);
		else if (rot == 0)
			stacks = rrb(stacks);
		steps--;
	}
	return (stacks);
}

t_stack	*sort(t_stack *stacks)
{
	int	size;

	size = ft_lstsize(stacks->a);
	if (is_input_sorted(stacks) == 1)
		return (stacks);
	if (size == 2)
		stacks = sort_2(stacks);
	else if (size == 3)
		stacks = sort_3(stacks);
	else
	{
		stacks = pb(stacks);
		stacks = pb(stacks);
		while (ft_lstsize(stacks->a) > 3)
			stacks = do_bigger_sort(stacks);
		stacks = final_rot_b(stacks);
		stacks = sort_3(stacks);
		stacks = push_back(stacks);
	}
	return (stacks);
}
