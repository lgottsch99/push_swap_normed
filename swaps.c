/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:24:44 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:45 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

typedef struct s_stack {
    t_list  *a;
    t_list  *b;
} t_stack;
*/

t_stack	*sa(t_stack *stack)
{
	ft_printf("sa\n");
	stack = real_sa(stack);
	return (stack);
}

t_stack	*real_sa(t_stack *stack)
{
	int		lstlen;
	t_list	*tmp;
	t_list	*third;

	lstlen = ft_lstsize(stack->a);
	if (lstlen <= 1)
		return (stack);
	tmp = stack->a;
	stack->a = stack->a->next;
	third = stack->a->next;
	stack->a->next = tmp;
	tmp->next = third;
	return (stack);
}

t_stack	*sb(t_stack *stack)
{
	ft_printf("sa\n");
	stack = real_sb(stack);
	return (stack);
}

t_stack	*real_sb(t_stack *stack)
{
	int		lstlen;
	t_list	*tmp;
	t_list	*third;

	lstlen = ft_lstsize(stack->b);
	if (lstlen <= 1)
		return (stack);
	tmp = stack->b;
	stack->b = stack->b->next;
	third = stack->b->next;
	stack->b->next = tmp;
	tmp->next = third;
	return (stack);
}

t_stack	*ss(t_stack *stacks)
{
	stacks = real_sa(stacks);
	stacks = real_sb(stacks);
	ft_printf("ss\n");
	return (stacks);
}
