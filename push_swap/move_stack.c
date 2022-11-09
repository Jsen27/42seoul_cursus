/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:08 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 21:48:45 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_up(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	mov_down(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}
