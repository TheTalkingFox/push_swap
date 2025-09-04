/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/26 22:19:14 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_to_pos(t_data *data, int position, int tmp_index)
{
	if (position == -1)
	{
		push(&data->a, delete_node(&data->b), 1);
		return (0);
	}
	else if (position < find_stack_size(&data->a) / 2)
		while (data->a.top->index != tmp_index)
			rotate(&data->a, 1);
	else
		while (data->a.top->index != tmp_index)
			rev_rotate(&data->a, 1);
	return (1);
}

void	update_and_push(t_data *data, int top_a, int top_b, int next_a)
{
	top_a = data->a.top->index;
	if (data->a.top->next)
		next_a = data->a.top->next->index;
	else
		next_a = data->a.top->index;
	push(&data->a, delete_node(&data->b), 1);
	if (top_b > top_a && top_b < next_a)
	{
		if (data->b.top != NULL && data->b.top->next != NULL
			&& data->b.top->index < data->b.top->next->index)
			double_swap(data);
		else
			swap(&data->a, 1);
	}
}

void	insert_num(t_data *data, int top_a, int top_b, int next_a)
{
	int		position;
	t_node	*tmp;

	position = 0;
	tmp = data->a.top;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			if (tmp->index < top_b && top_a > top_b)
				position = -1;
			break ;
		}
		if (tmp->index < top_b && tmp->next->index > top_b)
			break ;
		tmp = tmp->next;
		position++;
	}
	if (!rotate_to_pos(data, position, tmp->index))
		return ;
	update_and_push(data, top_a, top_b, next_a);
}

void	insert_min_max(t_data *data, int top_b)
{
	if (find_stack_size(&data->a) / 2 >= find_position(&data->a, data->min))
		while (data->a.top->index != data->min)
			rotate(&data->a, 1);
	else
		while (data->a.top->index != data->min)
			rev_rotate(&data->a, 1);
	push(&data->a, delete_node(&data->b), 1);
	if (top_b < data->min)
		data->min = top_b;
	if (top_b > data->max)
		data->max = top_b;
}

void	move_b(t_data *data)
{
	int	top_a;
	int	next_a;
	int	top_b;

	push(&data->a, delete_node(&data->b), 1);
	data->max = data->a.top->index;
	data->min = data->a.top->index;
	while (!is_empty(&data->b))
	{
		top_b = data->b.top->index;
		top_a = data->a.top->index;
		if (data->a.top->next)
			next_a = data->a.top->next->index;
		if (top_b < data->min || top_b > data->max)
			insert_min_max(data, top_b);
		else
			insert_num(data, top_a, top_b, next_a);
	}
	while (data->a.top->index != data->min)
		rev_rotate(&data->a, 1);
}
