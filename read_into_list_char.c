/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_list_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:22:27 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 17:21:27 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_whitespace(char *str, t_list *lst)
{
	char	**ptr;

	ptr = NULL;
	if (ft_strchr(str, ' ') != NULL)
	{
		ptr = ft_split(str, ' ');
		if (!ptr)
		{
			free_list(lst);
			exit(1);
		}
		return (ptr);
	}
	return (NULL);
}

void	add_to_list(t_list **list, char *ptr)
{
	t_list	*node;

	node = NULL;
	node = ft_lstnew(ptr);
	if (!node)
	{
		free_list(*list);
		exit (1);
	}
	ft_lstadd_back(list, node);
}

void	create_str_to_list(t_list **list, char *argv)
{
	int		len;
	char	*str;

	len = 0;
	while (argv[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free_list(*list);
		exit (1);
	}
	ft_memcpy(str, argv, (sizeof(char) * (len + 1)));
	str[len + 1] = '\0';
	add_to_list(list, str);
}

t_list	*read_into_list(int argc, char *argv[])
{
	t_list	*list;
	char	**ptr;
	int		i;

	ptr = NULL;
	list = NULL;
	i = 1;
	while (i < argc)
	{
		ptr = check_whitespace(argv[i], list);
		if (ptr)
		{
			while (*ptr)
			{
				add_to_list(&list, *ptr);
				ptr++;
			}
		}
		else
			create_str_to_list(&list, argv[i]);
		i++;
	}
	return (list);
}
