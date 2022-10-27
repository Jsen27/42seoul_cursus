/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:49:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 17:16:40 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void	b_to_a(t_node *a, t_node *b, int pivot_small, int pivot_big)
{
	int size;
	int ra = 0, rb = 0;

	size = b->size;
	while (size-- >= 0)
	{
		if (b->top->val < pivot_small)
		{
			rotate(b);
			rb++;
		}
		else
		{
			push(b, a);
			if (a->size > 1)
			{
				if (a->top->val < pivot_big)
					rotate(a);
					ra++;
			}
		}
	}
	while (ra || rb)
	{
		if (ra && rb)
		{
			re_rotate(a);
			re_rotate(b);
			ra--;
			rb--;
		}
		else if (ra)
		{
			rotate(a);
			ra--;
		}
		else if (rb)
		{
			rotate(b);
			rb--;
		}
	}
}

void	a_to_b(t_node *a, t_node *b, int r)
{
	int	size;
	int ra = 0, rb = 0;
	int pivot_small, pivot_big;

	size = r;
	find_pivot(a, &pivot_small, &pivot_big);
	while (size-- >= 0)
	{
		if (a->top->val >= pivot_big)
		{
			if (a->size > 1)
			{
				rotate(a);
				ra++;
			}
		}
		else
		{
			push(a, b);
			if (b->top->val >= pivot_small)
				if (b->size > 1)
				{
					rotate(b);
					rb++;
				}
		}
	}
	while (ra || rb)
	{
		if (ra && rb)
		{
			re_rotate(a);
			re_rotate(b);
			ra--;
			rb--;
		}
		else if (ra)
		{
			rotate(a);
			ra--;
		}
		else if (rb)
		{
			rotate(b);
			rb--;
		}
	}

}


void	stack_sort(t_node *a, t_node *b)
{
	t_number *temp;

	a_to_b(a, b, a->size);
	
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
