/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:43:44 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:48:21 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
STRATEGY NEW
1. read input into char list : The first argument should be at the top of the
 stack (be careful about the order).
	go thru input, for every arg:
		chcek if empty " " ""
		check for whitespace, if yes split
		append to list of input

2.check for valid input:
	go trhu whole list:
		check only digits, int range, dups

3.sort and print operations
	check if input already sorted, if yes do nothing
	if no: 
		push everything to b but in descending-sorted order, then push back
		before doing anything, always scan and calc for cheapest number

4. free list and all memory
*/

void	replace_int(t_list **list)
{
	int		*integer;
	int		nr;
	char	*str;
	int		i;
	t_list	*tmp;

	tmp = *list;
	i = 0;
	while (i < ft_lstsize(*list))
	{
		integer = NULL;
		integer = (int *)malloc(sizeof(int));
		if (!integer)
		{
			free_list(*list);
			exit(1);
		}
		str = (char *)tmp->content;
		nr = ft_atoi(str);
		ft_memcpy(integer, &nr, sizeof(int));
		free(tmp->content);
		tmp->content = integer;
		tmp = tmp->next;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc <= 1 || argv[1][0] == '\0')
		return (0);
	stacks.a = read_into_list(argc, argv);
	if (check_valid(&stacks.a) == 1)
	{
		ft_printf("Error\n");
		free_list(stacks.a);
		return (1);
	}
	replace_int(&stacks.a);
	stacks = *sort(&stacks);
	free_everything(&stacks);
	return (0);
}
