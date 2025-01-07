/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:24:22 by lgottsch          #+#    #+#             */
/*   Updated: 2025/01/07 18:58:53 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./full_libft/full_libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_info
{
	int	size_a;
	int	size_b;
	int	rot_a;
	int	rot_b;
	int	steps_a;
	int	steps_b;
	int	rr;
	int	rrr;
	int	total_steps;
	int	pos_a;
}	t_info;

//check_input.c
int		check_digits(char *str);
int		check_dups(t_list **argv, int i);
int		check_int_range(char *str);
int		check_range(char *str);
int		check_valid(t_list **list);

//swaps.c
t_stack	*sa(t_stack *stack);
t_stack	*real_sa(t_stack *stack);
t_stack	*sb(t_stack *stack);
t_stack	*real_sb(t_stack *stack);
t_stack	*ss(t_stack *stacks);

//push.c
t_stack	*pa(t_stack *stacks);
t_stack	*pb(t_stack *stacks);

//reverse
t_stack	*rra(t_stack *stacks);
t_stack	*rrb(t_stack *stacks);
t_stack	*rrr(t_stack *stacks);

//rotate
t_stack	*ra(t_stack *stacks);
t_stack	*rb(t_stack *stacks);
t_stack	*rr(t_stack *stacks);

//sort
t_stack	*sort(t_stack *stacks);
t_stack	*sort_5(t_stack *stacks);

//sort3
int		get_position(t_list *list, t_list *node);
t_stack	*sort_3(t_stack *stacks);

//read into list char
t_list	*read_into_list(int argc, char *argv[]);
void	create_str_to_list(t_list **list, char *argv);
void	add_to_list(t_list **list, char *ptr);
char	**check_whitespace(char *str, t_list *lst);

//bigger sort
t_stack	*do_bigger_sort(t_stack	*stacks);
int		calc_steps(t_list *lst, int pos, int *rot);
int		get_mid_pos(t_list *lst);

//big sort 2
void	rotation_a(int pos_a, int size_a, t_info *info, t_list *a);
int		rotation_b(t_list *node_a, t_list *b, t_info *info);
int		calc_steps_last(t_list *lst, int pos, int *rot);
int		calc_steps(t_list *lst, int pos, int *rot);
int		get_pos_in_b(t_list	*node_a, t_list	*b, t_list	*max);
t_list	*set_tmp(t_list *tmp, t_list *b);

//push back
t_stack	*push_back(t_stack *stacks);

//main
void	print_list(t_list *list);

//free
void	free_everything(t_stack *stacks);
void	free_list(t_list *lst);

//utils
void	print_int_list(t_list *list, char s);
void	print_list(t_list *list);
void	print_both(t_stack *stacks);
t_list	*get_max(t_list	*list);
t_list	*get_min(t_list	*list);
void	print_info(t_info *info);
int		set_mid_a(int size);
void	init_info(t_info *info, int pos, t_list *a);
int		get_mid_pos(t_list *lst);
t_list	*get_node_at_pos(t_list *list, int pos);
int		set_mid_b(int size, t_list *lst);

#endif