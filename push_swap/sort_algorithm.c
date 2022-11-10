/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:41 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/10 16:54:40 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_reversed(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] < stack[i + 1])
			return (0);
	}
	return (1);
}

int	check_three(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	if (i > 3)
		return (1);
	else
		return (0);
}

int	check_sort(int *stack, int numbers)
{
	int	i;

	i = 0;
	while (i < numbers - 1)
	{
		if (stack[i] > stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_algorithm(int *stack_a, int *stack_b, int numbers)
{
	if (!check_sort(stack_a, numbers))
		return ;
	else if (numbers <= 10)
	{
		if (numbers == 2)
			ft_rotate(stack_a, 'a');
		else if (numbers <= 5)
			sort_min(stack_a, stack_b, numbers);
		else if (check_reversed(stack_a))
			sort_reverse(stack_a, stack_b);
		else
			sort_ten(stack_a, stack_b);
	}
	else
		sort_radix(stack_a, stack_b, numbers);
}
