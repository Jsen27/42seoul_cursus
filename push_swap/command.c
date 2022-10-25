/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:56:03 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/25 20:28:18 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_sort(t_node *a, t_node *b, int com)
{
	if (com == 0)
		push(a, b);
	else if (com == 1)
		push(b, a);
	else if (com == 2)
		swap(a);
	else if (com == 3)
		swap(b);
	else if (com == 4)
	{
		swap(a);
		swap(b);
	}
	else if (com == 5)
		rotate(a);
	else if (com == 6)
		rotate(b);
	else if (com == 7)
	{
		rotate(a);
		rotate(b);
	}
	else if (com == 8)
		re_rotate(a);
	else if (com == 9)
		re_rotate(b);
	else if (com == 10)
	{
		re_rotate(a);
		re_rotate(b);
	}
}