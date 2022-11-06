/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:02:39 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:36:40 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	case_check(t_node *a, t_node *b, int r)
{
	if (r <= 3)
	{
		under_three(a, b, r, 2);
		return (0);
	}
	else if (r == 5)
	{
		five_all(a, b, 5, 2);
		return (0);
	}
	else
		return (1);
}

void	b_rotate(t_node *a, t_node *b, t_val val)
{
	int	aa;
	int	bb;

	aa = val.ra;
	bb = val.rb;
	while (aa || bb)
	{
		if ((aa && bb) && (b->size > 1 && a->size > 1))
		{
			re_rotate(a--);
			re_rotate(b--);
		}
		else if (aa && a->size > 1)
			re_rotate(a--);
		else if (bb && b->size > 1)
			re_rotate(b--);
	}
}

void	b_push_rotate(t_node *a, t_node *b, t_val *val, int r)
{
	if (b->top->val < val->small)
	{
		if (b->size > 1)
		{
			rotate(b);
			val->rb++;
		}
	}
	else
	{
		push(b, a);
		val->pa++;
		if (a->top->val < val->big)
			if (a->size > 1)
			{
				rotate(a);
				val->ra++;
			}
	}
}
void	b_to_a(t_node *a, t_node *b, int r)
{
	t_val	val;

	if (!case_check(a, b, r))
		return ;
	val_init(b, &val);
	while (r--)
		b_push_rotate(a, b, &val, r);
	a_to_b(a, b, val.pa - val.ra);
	b_rotate(a, b, val);
	a_to_b(a, b, val.ra);
	b_to_a(a, b, val.rb);
}