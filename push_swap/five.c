/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:44:45 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:33:17 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	five_b(t_node *a, t_node *b, int r)
{
	int	mid;
	int	ps;
	int	rt;

	ps = 0;
	rt = 0;
	mid = find_mid_five(b);
	while (r--)
	{
		if (b->top->val < mid)
		{
			push(b, a);
			ps++;
		}
		else
		{
			rotate(b);
			rt++;
		}
		if (ps == 2)
			break;
	}
	while (rt-- && b->size > 1)
		re_rotate(b);
}

static void	five_a(t_node *a, t_node *b, int r)
{
	int	mid;
	int	ps;
	int	rt;

	ps = 0;
	rt = 0;
	mid = find_mid_five(a);
	while (r--)
	{
		if (a->top->val < mid)
		{
			push(a, b);
			ps++;
		}
		else
		{
			rotate(a);
			rt++;
		}
		if (ps == 2)
			break;
	}
	while (rt-- && a->size > 1)
		re_rotate(a);
}

void	five_all(t_node *a, t_node *b, int r, int type)
{
	if (type == 1)
		five_a(a, b, r);
	else if (type == 2)
		five_b(a, b, r);
	three_a(a);
	two_all(a, b, type);
}