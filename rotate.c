/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:24:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:15:32 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. 
The first element becomes the last one.
rr : ra and rb at the same time.
*/

t_stack	*real_ra(t_stack *stacks)
{
	int		size;
	t_list	*first;

	size = ft_lstsize(stacks->a);
	if (size <= 1)
		return (stacks);
	first = stacks->a;
	stacks->a = first->next;
	first->next = NULL;
	ft_lstadd_back(&stacks->a, first);
	return (stacks);
}

t_stack	*ra(t_stack *stacks)
{
	ft_printf("ra\n");
	stacks = real_ra(stacks);
	return (stacks);
}

t_stack	*real_rb(t_stack *stacks)
{
	int		size;
	t_list	*first;

	size = ft_lstsize(stacks->b);
	if (size <= 1)
		return (stacks);
	first = stacks->b;
	stacks->b = first->next;
	first->next = NULL;
	ft_lstadd_back(&stacks->b, first);
	return (stacks);
}

t_stack	*rb(t_stack *stacks)
{
	ft_printf("rb\n");
	stacks = real_rb(stacks);
	return (stacks);
}

t_stack	*rr(t_stack *stacks)
{
	ft_printf("rr\n");
	stacks = real_ra(stacks);
	stacks = real_rb(stacks);
	return (stacks);
}
