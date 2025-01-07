/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:21:08 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:02:31 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *list, t_list *node)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = 1;
	while (tmp)
	{
		if (*(int *)tmp->content == *(int *)node->content)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*if_minpos3(int maxpos, t_stack *stacks)
{
	if (maxpos == 1)
	{
		stacks = ra(stacks);
		stacks = sa(stacks);
	}
	if (maxpos == 2)
		stacks = rra(stacks);
	return (stacks);
}

t_stack	*if_minpos2(int maxpos, t_stack *stacks)
{
	if (maxpos == 1)
		stacks = ra(stacks);
	if (maxpos == 3)
		stacks = sa(stacks);
	return (stacks);
}

t_stack	*sort_3(t_stack *stacks)
{
	t_list	*min;
	t_list	*max;
	t_list	*list;
	int		minpos;
	int		maxpos;

	list = stacks->a;
	min = get_min(list);
	minpos = get_position(list, min);
	max = get_max(list);
	maxpos = get_position(list, max);
	if (minpos == 1)
	{
		stacks = rra(stacks);
		stacks = sa(stacks);
	}
	if (minpos == 2)
		stacks = if_minpos2(maxpos, stacks);
	if (minpos == 3)
		stacks = if_minpos3(maxpos, stacks);
	return (stacks);
}
