/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:19 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/14 20:58:41 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_ten(int *stack_a, int *stack_b)
{
	int	min;

	min = 1;
	while (stack_a[0])
	{
		if (stack_a[0] == min)
		{
			ft_push(stack_a, stack_b, 'b');
			min++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
	while (stack_b[0])
		ft_push(stack_b, stack_a, 'a');
}

void	sort_reverse(int *stack_a, int *stack_b)
{
	while (stack_a[0] != 0)
		ft_push(stack_a, stack_b, 'b');
	while (stack_b[0] != 0)
	{
		ft_re_rotate(stack_b, 'b');
		ft_push(stack_b, stack_a, 'a');
	}
}

void	sort_three(int *stack_a)
{
	if (stack_a[1] == 2)
	{
		ft_swap(stack_a, 'a');
		ft_re_rotate(stack_a, 'a');
	}
	else if (stack_a[0] == 3)
		ft_rotate(stack_a, 'a');
	else if (stack_a[2] == 3)
		ft_swap(stack_a, 'a');
	else if (stack_a[2] == 1)
		ft_re_rotate(stack_a, 'a');
	else
	{
		ft_swap (stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
}

void	sort_min(int *stack_a, int *stack_b, int max)
{
	while (check_three(stack_a))
	{
		if (stack_a[0] > 3)
			ft_push(stack_a, stack_b, 'b');
		else if (stack_a[max - 1] > 3)
		{
			ft_re_rotate(stack_a, 'a');
			ft_push(stack_a, stack_b, 'b');
		}
		else
			ft_rotate(stack_a, 'a');
	}
	if (check_sort(stack_a, 3))
		sort_three(stack_a);
	if (stack_b[0] < stack_b[1])
		ft_rotate(stack_b, 'b');
	while (stack_b[0] != 0)
		ft_push(stack_b, stack_a, 'a');
	while (stack_a[0] != 1)
		ft_rotate(stack_a, 'a');
}
