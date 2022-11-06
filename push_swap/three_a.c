/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:43:41 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:34:11 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	three_bot_min_a(t_node *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->prev->val == max)
			re_rotate(a);
		else if (a->top->val == max)
		{
			swap(a);
			re_rotate(a);
		}
	}
	else if (a->size > 1)
	{
		if (a->top->val == max)
			swap(a);
		rotate(a);
		swap(a);
		re_rotate(a);
		swap(a);
	}
}

static void	three_mid_min_a(t_node *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->val == max)
			rotate(a);
		else if (a->bottom->val == max)
			swap(a);
	}
	else if (a->size > 1)
	{
		swap(a);
		if (a->top->prev->val == max)
		{
			rotate(a);
			swap(a);
			re_rotate(a);
		}
	}
}

static void	three_top_min_a(t_node *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->prev->val == max)
		{
			swap(a);
			rotate(a);
		}
	}
	else if (a->size > 1)
	{
		if (a->top->prev->val == max)
		{
			rotate(a);
			swap(a);
			re_rotate(a);
		}
	}
}

void	three_a(t_node *a)
{
	int	min;
	int	max;

	min = find_min(a);
	max = find_max(a);
	if (a->top->val == min)
		three_top_min_a(a, max);
	else if (a->top->prev->val == min)
		three_mid_min_a(a, max);
	else if (a->top->prev->prev->val == max)
		three_bot_min_a(a, max);
}