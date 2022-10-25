/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:49:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/25 21:30:32 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_node *a, t_node *b, int pivot_small, int pivot_big)
{
	int	size;

	size = a->size - 1;
	while (size-- > 0)
	{
		if (a->top->val < pivot_big)
		{
			command_sort(a, b, 0);
			if (b->top)
				if (b->top->val < pivot_small)
					command_sort(a, b, 6);
		}
		else
			command_sort(a, b, 5);
	}
	if (a->top->val < pivot_big)
	{
		command_sort(a, b, 0);
		if (b->top->val < pivot_small)
			command_sort(a, b, 6);
	}
	else
		command_sort(a, b, 5);
}

#include<stdio.h>

void	stack_sort(t_node *a, t_node *b)
{
	int	pivot_small;
	int	pivot_big;
	t_number *temp;
	
	find_pivot(a, &pivot_small, &pivot_big);
	a_to_b(a, b, pivot_small, pivot_big);
	
	printf("----------a--------\n");
	temp = a->bottom;
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
	}

	printf("----------b--------\n");
	temp = b->bottom;
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
	}
}
