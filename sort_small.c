/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/02 19:02:21 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	sec;
	int	third;

	first = stack->top->index;
	sec = stack->top->next->index;
	third = stack->top->next->next->index;
	if (first > sec && sec < third && first < third)
		swap(stack, 1);
	else if (first > sec && sec > third)
	{
		swap(stack, 1);
		rev_rotate(stack, 1);
	}
	else if (first > sec && sec < third && first > third)
		rotate(stack, 1);
	else if (first < sec && sec > third && first < third)
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (first < sec && sec > third)
		rev_rotate(stack, 1);
}

void	finish_sort_five(t_data *data, int i)
{
	sort_three(&data->a);
	while (--i != 0)
		push(&data->a, delete_node(&data->b), 1);
}

void	sort_five(t_data *data, int iterations)
{
	int		min;
	int		i;
	t_node	*tmp;
	int		pos;

	i = 0;
	while (++i < iterations)
	{
		min = data->a.top->index;
		tmp = data->a.top;
		while (tmp)
		{
			if (tmp->index < min)
				min = tmp->index;
			tmp = tmp->next;
		}
		pos = find_position(&data->a, min);
		while (data->a.top->index != min)
			if (pos <= find_stack_size(&data->a) / 2)
				rotate(&data->a, 1);
		else
			rev_rotate(&data->a, 1);
		push(&data->b, delete_node(&data->a), 2);
	}
	finish_sort_five(data, i);
}

void	sort_small(t_data *data)
{
	int	iterations;

	iterations = 2;
	if (data->size == 2)
	{
		if (data->a.top->index > data->a.top->next->index)
			rotate(&data->a, 1);
		free_stack(&data->a);
		exit(0);
	}
	else if (data->size == 3)
	{
		sort_three(&data->a);
		free_stack(&data->a);
		exit(0);
	}
	else if (data->size <= 5)
	{
		if (data->size == 5)
			iterations = 3;
		sort_five(data, iterations);
		free_stack(&data->a);
		exit(0);
	}
}
