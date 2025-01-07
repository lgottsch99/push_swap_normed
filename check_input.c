/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:26:50 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 18:57:10 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_range(char *str)
{
	long	input;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[0] == '+')
		i++;
	input = str[i] - '0';
	i++;
	while (str[i])
	{
		input = input * 10;
		input = input + (str[i] - '0');
		i++;
	}
	input = input * sign;
	if (input < -2147483648 || input > 2147483647)
		return (1);
	return (0);
}

int	check_int_range(char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen < 10)
		return (0);
	if (strlen == 10)
	{
		if (str[0] == '-' || str[0] == '+')
			return (0);
	}
	if (strlen > 11)
		return (1);
	if (strlen == 11)
	{
		if (str[0] != '-' && str[0] != '+')
			return (1);
	}
	if (check_range(str) == 1)
		return (1);
	return (0);
}

int	check_dups(t_list **list, int i)
{
	t_list	*tmp;
	int		og;
	int		cmp;
	int		y;

	tmp = *list;
	y = 0;
	while (y < i)
	{
		tmp = tmp->next;
		y++;
	}
	og = ft_atoi((char *)tmp->content);
	tmp = *list;
	y = 0;
	while (y < i)
	{
		cmp = ft_atoi((char *)tmp->content);
		if (og == cmp)
			return (1);
		tmp = tmp->next;
		y++;
	}
	return (0);
}

int	check_digits(char *str)
{
	int	y;
	int	check;

	y = 0;
	check = 0;
	while (str[y])
	{
		if (y == 0 && !ft_isdigit(str[y]))
		{
			if (str[y] != '-' && str[y] != '+')
				check += 1;
			if ((str[y] == '-' || str[y] == '+') && !str[y + 1])
				check += 1;
		}
		else if (y > 0 && !ft_isdigit(str[y]))
			check += 1;
		y++;
	}
	if (check > 0)
		return (1);
	return (0);
}

int	check_valid(t_list **list)
{
	t_list	*ptr;
	int		size;
	int		i;

	size = ft_lstsize(*list);
	ptr = *list;
	i = 0;
	while (i < size)
	{
		if (check_digits(ptr->content) == 1)
			return (1);
		if (check_int_range(ptr->content) == 1)
			return (1);
		if (check_dups(list, i) == 1)
			return (1);
		ptr = ptr->next;
		i++;
	}
	return (0);
}
