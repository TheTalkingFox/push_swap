/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:12:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/02 18:59:07 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *c)
{
	long long	number;
	int			negative;

	number = 0;
	negative = 1;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			negative = -1;
		c++;
	}
	if (*c == 0)
		while (*c == 0)
			c++;
	while (*c >= '0' && *c <= '9')
	{
		number = number * 10 + *c - '0';
		c++;
	}
	number *= negative;
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (number);
}

int	ft_strlength(char *str)
{
	int	len;

	len = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (-1);
	while (*str == '0')
		str++;
	while (*str)
	{
		str++;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

int	count_dig(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (10);
	else if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	find_size(char **arg, int i)
{
	int	j;

	j = i;
	while (arg[j])
		j++;
	return (j - i);
}

int	is_zero(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}
