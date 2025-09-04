/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/26 22:09:50 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack, t_node *node, int stack_name)
{
	node->next = stack->top;
	stack->top = node;
	if (stack_name == 1)
		ft_printf("pa\n");
	else if (stack_name == 2)
		ft_printf("pb\n");
	return (1);
}

t_node	*delete_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	return (tmp);
}

void	rotate(t_stack *stack, int stack_name)
{
	t_node	*first;
	t_node	*tmp;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	if (stack_name == 1)
		ft_printf("ra\n");
	else if (stack_name == 2)
		ft_printf("rb\n");
}

void	rev_rotate(t_stack *stack, int stack_name)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->top)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev)
		return ;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (stack_name == 1)
		ft_printf("rra\n");
	else if (stack_name == 2)
		ft_printf("rrb\n");
}

void	swap(t_stack *stack, int stack_name)
{
	t_node	*first;
	t_node	*second;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack_name == 1)
		ft_printf("sa\n");
	else if (stack_name == 2)
		ft_printf("sb\n");
}
