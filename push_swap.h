/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/26 22:32:30 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
	int				chunk;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

typedef struct s_data
{
	int				size;
	int				*arr;
	t_stack			a;
	t_stack			b;
	int				min;
	int				max;
}					t_data;

void				double_swap(t_data *data);

int					ft_atol(char *c);
int					ft_strlength(char *str);
int					count_dig(int num);
int					find_size(char **arg, int i);
int					is_zero(char *str);

int					check_input(char ***arg, int i, t_data *data);
void				free_arg(char **arg);
int					loop_intput(char **arg, int i, int *arr);
int					check_num(char **arg, int i, int *num);
int					push_new(t_stack *stack, int value);

void				move_a(t_data *data, int chunk_num, int chunk_size);
int					find_position(t_stack *stack, int index);
int					find_stack_size(t_stack *stack);

void				move_b(t_data *data);
void				insert_min_max(t_data *data, int top_b);
void				insert_num(t_data *data, int top_a, int top_b, int next_a);
void				update_and_push(t_data *data, int top_a, int top_b,
						int next_a);
int					rotate_to_pos(t_data *data, int position, int tmp_index);

int					push(t_stack *stack, t_node *node, int stack_name);
t_node				*delete_node(t_stack *stack);
void				rotate(t_stack *stack, int stack_name);
void				rev_rotate(t_stack *stack, int stack_name);
void				swap(t_stack *stack, int stack_name);

int					check_argc(int argc, char **argv, char ***arg);
void				push_swap(t_data *data);

void				sort_small(t_data *data);
void				sort_five(t_data *data, int iterations);
void				finish_sort_five(t_data *data, int i);
void				sort_three(t_stack *stack);

t_node				*make_new_node(int value);
int					is_empty(t_stack *stack);
void				free_stack(t_stack *stack);
void				assign_indexes(t_node *stack, int size);
int					assign_chunks(t_data *data, int chunk_count);
#endif