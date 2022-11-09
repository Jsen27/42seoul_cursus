/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:42:05 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 16:14:42 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overlap(int i, int *check)
{
	int	j;

	j = 0;
	while (check[j])
	{
		if (check[j] == i + 1)
			return (0);
		j++;
	}
	return (1);
}

static void	arr_to_stack(long int *arr, int *stack_a, int numbers, int *check)
{
	static int	val;
	long int	min;
	int			i;
	int			pos;

	i = 0;
	pos = 0;
	min = 2147483648;
	while (i < numbers)
	{
		if (arr[i] < min && check_overlap(i, check))
		{
			pos = i;
			min = arr[i];
		}
		i++;
	}
	check[val] = pos + 1;
	stack_a[pos] = ++val;
}

int	*make_stack(long int *arr, int numbers)
{
	int	*stack_a;
	int	*check;
	int	cnt;

	cnt = 0;
	check = ft_calloc(numbers + 1, sizeof(int));
	stack_a = ft_calloc(numbers + 2, sizeof(int));
	while (cnt++ < numbers)
		arr_to_stack(arr, stack_a, numbers, check);
	free(check);
	free(arr);
	return (stack_a);
}
