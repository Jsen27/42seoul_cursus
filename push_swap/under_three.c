/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:39:36 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:11:22 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_all(t_node *a, t_node *b, int type)
{
	if (type == 1)
		swap(a);
	else
	{
		if (b->top->val < b->top->prev->val)
			swap(b);
		push(b, a);
		push(b, a);
	}
}

void	under_three(t_node *a, t_node *b, int r, int type)
{
	if (r == 3)
	{
		if (type == 1)
			three_a(a);
		else if (type == 2)
			three_b(a, b);
	}
	else if (r == 2)
		two_all(a, b, type);
	else if (r == 1 && type == 2)
		push(b, a);
}
