/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/26 22:28:26 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stack_size(t_stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack->top;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	find_position(t_stack *stack, int index)
{
	t_node	*tmp;
	int		position;

	position = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index == index)
			return (position);
		tmp = tmp->next;
		position++;
	}
	return (-1);
}

void	move_a(t_data *data, int chunk_num, int chunk_size)
{
	int	moved;
	int	position;

	moved = 0;
	while (moved < chunk_size)
	{
		if (is_empty(&data->a))
			break ;
		position = find_position(&data->a, data->a.top->index);
		if (position == 1)
			swap(&data->a, 1);
		else if (position < find_stack_size(&data->a) / 2)
			while (data->a.top->chunk != chunk_num)
				rotate(&data->a, 1);
		else
			while (data->a.top->chunk != chunk_num)
				rev_rotate(&data->a, 1);
		push(&data->b, delete_node(&data->a), 2);
		moved++;
	}
}
