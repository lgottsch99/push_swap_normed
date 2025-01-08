/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:25:08 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/08 18:14:04 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		ft_printf("char list content: %s\n", (char *)list->content);
// 		list = list->next;
// 	}
// }

// void	print_int_list(t_list *list, char s)
// {
// 	int	i;

// 	while (list)
// 	{
// 		i = *(int *)list->content;
// 		ft_printf("int list %c", s);
// 		ft_printf(": %i\n", i);
// 		list = list->next;
// 	}
// }

// void	print_both(t_stack *stacks)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int		i;
// 	int		y;

// 	a = stacks->a;
// 	b = stacks->b;
// 	while (a || b)
// 	{
// 		i = 0;
// 		y = 0;
// 		if (a)
// 		{
// 			i = *(int *)a->content;
// 			ft_printf("stack a: %i", i);
// 			a = a->next;
// 		}
// 		else
// 			ft_printf("          ", i);
// 		ft_printf("|	");
// 		if (b)
// 		{
// 			y = *(int *)b->content;
// 			ft_printf("stack b: %i\n", y);
// 			b = b->next;
// 		}
// 		else
// 			ft_printf("\n");
// 	}
// 	ft_printf("\n");
// }

// void	print_info(t_info *info)
// {
// 	ft_printf("size_a; %i\n", info->size_a);
// 	ft_printf("size_b; %i\n", info->size_b);
// 	ft_printf("rot_a; %i\n", info->rot_a);
// 	ft_printf("rot_b; %i\n", info->rot_b);
// 	ft_printf("steps_a; %i\n", info->steps_a);
// 	ft_printf("steps_b; %i\n", info->steps_b);
// 	ft_printf("rr; %i\n", info->rr);
// 	ft_printf("rrr; %i\n", info->rrr);
// 	ft_printf("total steps; %i\n", info->total_steps);
// 	ft_printf(" pos in a; %i\n\n", info->pos_a);
// }

t_list	*get_min(t_list	*list)
{
	t_list	*min;

	min = list;
	while (list)
	{
		if (*(int *)min->content > *(int *)list->content)
			min = list;
		list = list->next;
	}
	return (min);
}

t_list	*get_max(t_list	*list)
{
	t_list	*max;

	max = list;
	while (list)
	{
		if (list)
		{
			if (*(int *)max->content < *(int *)list->content)
				max = list;
		}
		list = list->next;
	}
	return (max);
}

int	get_mid_pos(t_list *lst)
{
	int	mid;
	int	size;

	size = ft_lstsize(lst);
	if (size % 2 == 1)
		mid = size / 2 + 1;
	else
		mid = size / 2;
	return (mid);
}

t_list	*get_node_at_pos(t_list *list, int pos)
{
	t_list	*node;
	int		i;

	node = list;
	i = 1;
	while (i != pos)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	set_mid_a(int size)
{
	int	mid;

	if (size <= 3)
		mid = 2;
	else
		mid = size / 2;
	return (mid);
}
