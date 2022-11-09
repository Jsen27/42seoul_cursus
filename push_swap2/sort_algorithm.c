/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:41 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 17:01:09 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		if (stack_a[i] > stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_algorithm(int *stack_a, int *stack_b, int numbers)
{
	if (!check_sort(stack_a))
		return ;
	else if (numbers == 2)
		ft_rotate(stack_a, 'a');

}