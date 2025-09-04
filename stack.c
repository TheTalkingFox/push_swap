/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/25 19:14:51 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->chunk = -1;
	node->next = NULL;
	return (node);
}

void	assign_indexes(t_node *stack, int size)
{
	int		index;
	t_node	*tmp;
	t_node	*min_node;

	index = 0;
	while (index < size)
	{
		tmp = stack;
		min_node = NULL;
		while (tmp)
		{
			if ((min_node == NULL || tmp->value < min_node->value)
				&& tmp->index == -1)
				min_node = tmp;
			tmp = tmp->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}

int	assign_chunks(t_data *data, int chunk_count)
{
	int		chunk;
	t_node	*current;

	current = data->a.top;
	while (current)
	{
		chunk = current->index / chunk_count;
		current->chunk = chunk;
		current = current->next;
	}
	return ((data->size + chunk_count - 1) / chunk_count);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top != NULL)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}
