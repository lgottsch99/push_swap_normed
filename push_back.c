/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:25:37 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:42:07 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_steps_a(int size, int pos, int *rot)
{
	int	steps;
	int	mid;

	mid = set_mid_a(size);
	steps = 0;
	if (pos <= mid)
	{
		*rot = 1;
		while (pos > 1)
		{
			pos--;
			steps++;
		}
	}
	else if (pos > mid)
	{
		*rot = 0;
		while (pos < (size + 1))
		{
			pos++;
			steps++;
		}
	}
	return (steps);
}

int	inbetween(int nr_b, t_list *a)
{
	t_list	*current;
	t_list	*one_before;
	int		pos;

	pos = 1;
	current = a;
	one_before = ft_lstlast(a);
	while (!(*(int *)current->content > nr_b
			&& *(int *)one_before->content < nr_b) && pos <= ft_lstsize(a))
	{
		if (!one_before->next)
			one_before = a;
		else
			one_before = current;
		if (current->next)
			current = current->next;
		else
			break ;
		pos++;
	}
	return (pos);
}

int	get_pos_in_a(int nr_b, t_list *a)
{
	int		pos;
	t_list	*min;
	t_list	*max;

	min = get_min(a);
	max = get_max(a);
	pos = 0;
	if (nr_b < *(int *)min->content || nr_b > *(int *)max->content)
		pos = get_position(a, min);
	else
		pos = inbetween(nr_b, a);
	return (pos);
}

t_stack	*final_rot_a(t_stack *stacks)
{
	t_list	*min;
	int		minpos;
	int		steps;
	int		rot;

	rot = -1;
	min = get_min(stacks->a);
	minpos = get_position(stacks->a, min);
	steps = calc_steps_a(ft_lstsize(stacks->a), minpos, &rot);
	while (steps > 0)
	{
		if (rot == 1)
			stacks = ra(stacks);
		else if (rot == 0)
			stacks = rra(stacks);
		steps--;
	}
	return (stacks);
}

t_stack	*push_back(t_stack *stacks)
{
	int	pos_a;
	int	rot;
	int	steps;

	rot = -1;
	steps = 0;
	while (ft_lstsize(stacks->b) > 0)
	{
		pos_a = get_pos_in_a(*(int *)stacks->b->content, stacks->a);
		steps = calc_steps_a(ft_lstsize(stacks->a), pos_a, &rot);
		while (steps > 0)
		{
			if (rot == 1)
				stacks = ra(stacks);
			else if (rot == 0)
				stacks = rra(stacks);
			steps--;
		}
		stacks = pa(stacks);
	}
	stacks = final_rot_a(stacks);
	return (stacks);
}
