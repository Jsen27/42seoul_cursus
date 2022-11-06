/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:02:56 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:54:51 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	case_check(t_node *a, t_node *b, int r)
{
	if (r <= 3)
	{
		under_three(a, b, r, 1);
		return (0);
	}
	else if (r == 5)
	{
		five_all(a, b, 5, 1);
		return (0);
	}
	else
		return (1);
}

void	a_rotate(t_node *a, t_node *b, t_val val)
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
		else if (aa && (a->size > 1))
			re_rotate(a--);
		else if (bb && (b->size > 1))
			re_rotate(b--);
		else
			break;
	}
}

void	a_push_rotate(t_node *a, t_node *b, t_val *val, int r)
{
	if (a->top->val >= val->big)
	{
		if (a->size > 1)
		{
			rotate(a);
			val->ra++;
		}
	}
	else
	{
		push(a, b);
		val->pa++;
		if (b->top->val >= val->small)
			if (b->size > 1)
			{
				rotate(b);
				val->rb++;
			}
	}
}

void	a_to_b(t_node *a, t_node *b, int r)
{
	t_val	val;
	
	if (!case_check(a, b, r))
		return ;
	val_init(a, &val);
	while (r--)
		a_push_rotate(a, b, &val, r);
	a_rotate(a, b, val);
	a_to_b(a, b, val.ra);
	b_to_a(a, b, val.rb);
	b_to_a(a, b, val.pb - val.rb);
}