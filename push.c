/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:51 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:23:17 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

typedef struct s_stack {
    t_list  *a;
    t_list  *b;
} t_stack;
*/

t_stack	*pa(t_stack *stacks)
{
	t_list	*tmp;
	int		len;

	len = ft_lstsize(stacks->b);
	if (len == 0)
		return (stacks);
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = NULL;
	ft_lstadd_front(&stacks->a, tmp);
	ft_printf("pa\n");
	return (stacks);
}

t_stack	*pb(t_stack *stacks)
{
	t_list	*tmp;
	int		len;

	len = ft_lstsize(stacks->a);
	if (len == 0)
		return (stacks);
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = NULL;
	ft_lstadd_front(&stacks->b, tmp);
	ft_printf("pb\n");
	return (stacks);
}
