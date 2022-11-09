/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 16:54:22 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_re_rotate(int *stack, char type)
{
	int	temp;
	int	i;

	i = 0;
	while (stack[i])
		i++;
	temp = stack[i - 1];
	stack[i - 1] = 0;
	mov_down(stack);
	stack[0] = temp;
	if (type == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	ft_rotate(int *stack, char type)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack[0];
	mov_up(stack);
	while (stack[i])
		i++;
	stack[i] = temp;
	if (type == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_push(int *to, int *from, char type)
{
	mov_down(to);
	to[0] = from[0];
	mov_up(from);
	if (type == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	ft_swap(int *stack, char type)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}