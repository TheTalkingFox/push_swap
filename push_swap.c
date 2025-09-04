/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/02 19:20:44 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = data->a.top;
	while (++i < data->size)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_data *data)
{
	int	chunk_size;
	int	chunk;
	int	next_chunk;

	chunk = -1;
	next_chunk = 1;
	data->b.top = NULL;
	chunk_size = 0;
	if (is_sorted(data))
	{
		free_stack(&data->a);
		exit(0);
	}
	else if (data->size <= 5)
		sort_small(data);
	else if (data->size <= 10)
		chunk_size = 3;
	else if (data->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 40;
	assign_chunks(data, chunk_size);
	while (++chunk <= (data->size / chunk_size))
		move_a(data, chunk, chunk_size);
	move_b(data);
}

int	check_argc(int argc, char **argv, char ***arg)
{
	if (argc > 2)
		*arg = argv;
	else
		exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		start;
	char	**arg;
	t_data	data;

	start = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (!*arg)
			return (free(arg), write(2, "Error\n", 6), 1);
	}
	else
		start = check_argc(argc, argv, &arg);
	if (!check_input(&arg, start, &data))
	{
		if (start == 0)
			free_arg(arg);
		exit(1);
	}
	push_swap(&data);
	free_stack(&data.a);
	exit(0);
}
