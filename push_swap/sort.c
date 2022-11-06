/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:49:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:21:32 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void	val_init(t_node *lst, t_val *val)
{
	find_pivot(lst, &val->small, &val->big);
	val->ra = 0;
	val->pa = 0;
	val->pb = 0;
	val->rb = 0;
}

void	stack_sort(t_node *a, t_node *b)
{
	t_number	*temp;

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
