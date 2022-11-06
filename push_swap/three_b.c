/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:04:06 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:34:33 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_bot_min_b(t_node *b, int max)
{
	if (b->top->prev->val == max)
		swap(b);
}

static void	three_mid_min_b(t_node *b, int max)
{
	if (b->size == 3)
	{
		re_rotate(b);
		if (b->top->prev->val == max)
			swap(b);
	}
	else if (b->size > 1)
	{
		rotate(b);
		swap(b);
		re_rotate(b);
		if (b->top->prev->val == max)
			swap(b);
	}
}

static void	three_top_min_b(t_node *b, int max)
{
	if (b->size == 3)
	{
		rotate(b);
		if (b->top->prev->val == max)
			swap(b);
	}
	else if (b->size > 1)
	{
		swap(b);
		rotate(b);
		swap(b);
		re_rotate(b);
		if (b->top->prev->val == max)
			swap(b);
	}
}

void	three_b(t_node *a, t_node *b)
{
	int	min;
	int	max;

	min = find_min(b);
	max = find_max(b);
	if (b->top->val == min)
		three_top_min_b(b, max);
	else if (b->top->prev->val == min)
		three_mid_min_b(b, max);
	else if (b->top->prev->prev->val == min)
		three_bot_min_b(b, max);
	push(b, a);
	push(b, a);
	push(b, a);
}
