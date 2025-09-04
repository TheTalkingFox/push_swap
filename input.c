/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/26 22:23:32 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_new(t_stack *stack, int value)
{
	t_node	*node;

	node = make_new_node(value);
	if (node == NULL)
		return (write(2, "Error\n", 6), 0);
	node->next = stack->top;
	stack->top = node;
	return (1);
}

int	check_num(char **arg, int i, int *num)
{
	int	len;

	len = ft_strlength(arg[i]);
	if (len == -1)
		return (0);
	if (is_zero(arg[i]) == len)
		*num = 0;
	else
	{
		*num = ft_atol(arg[i]);
		if (len != count_dig(*num))
			return (0);
	}
	return (1);
}

int	loop_intput(char **arg, int i, int *arr)
{
	int	num;
	int	copy_num;
	int	j;

	j = 0;
	while (arg[i])
	{
		if (!check_num(arg, i, &num))
			return (0);
		copy_num = -1;
		while (++copy_num < j)
			if (arr[copy_num] == num)
				return (0);
		arr[j++] = num;
		i++;
	}
	if (j == 1)
		return (1);
	return (j);
}

void	free_arg(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		free(arg[i]);
	free(arg);
}

int	check_input(char ***arg, int i, t_data *data)
{
	int	*arr;
	int	j;

	data->size = find_size(*arg, i);
	arr = (int *)malloc(data->size * sizeof(int));
	if (!arr)
		return (write(2, "Error\n", 6), 0);
	j = loop_intput(*arg, i, arr);
	if (j == 0)
		return (write(2, "Error\n", 6), free(arr), 0);
	else if (j == 1)
		return (free(arr), 0);
	data->a.top = NULL;
	while (--j >= 0)
		if (!push_new(&data->a, arr[j]))
			return (free(arr), free_stack(&data->a), 0);
	assign_indexes(data->a.top, data->size);
	if (i == 0)
		free_arg(*arg);
	return (free(arr), 1);
}
