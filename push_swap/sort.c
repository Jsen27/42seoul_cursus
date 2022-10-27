/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:49:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 17:53:30 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void	push_retate(t_node *to, t_node *from, t_val *val, int r)
{
	// r 몇개이상 ? 
	if (to->top->val >= val->big)
		if (to->size > 1)
		{
			rotate(to);
			val->ra++;
		}
	else
	{
		push(to, from);
		val->pa++;
		if (from->top->val >= val->small)
			if (from->size > 1)
			{
				rotate(from);
				val->rb++;
			}
	}
}

void	val_init(t_node *lst, t_val *val)
{
	find_pivot(lst, val->small, val->big);
	val->ra = 0;
	val->pa = 0;
	val->pb = 0;
	val->rb = 0;
}

void	a_to_b(t_node *a, t_node *b, int r)
{
	int	size;
	int ra = 0, rb = 0;
	int pivot_small, pivot_big;
	t_val	val;

	size = r;
	val_init(a, &val);
	while (size-- >= 0)
		push_retate(a, b, &val, r);
		
	while (val.ra || val.rb)
	{
		if (val.ra && val.rb)
		{
			re_rotate(a);
			re_rotate(b);
			val.ra--;
			val.rb--;
		}
		else if (val.ra)
		{
			rotate(a);
			val.ra--;
		}
		else if (val.rb)
		{
			rotate(b);
			val.rb--;
		}
	}
	a_to_b (a, b, val.ra);
	//b rb
	//b pb - rb
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
