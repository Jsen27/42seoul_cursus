/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:53:32 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/20 20:00:07 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate(t_node *lst)
{
	t_number	*ttemp;
	t_number	*btemp;

	ttemp = lst->bottom;
	btemp = lst->bottom->next;
	lst->bottom->prev = lst->top;
	lst->top->next = lst->bottom;
	lst->bottom->next->prev = NULL;
	lst->bottom->next = NULL;
	lst->top = ttemp;
	lst->bottom = btemp;
}

void	rotate(t_node *lst)
{
	t_number	*ttemp;
	t_number	*btemp;

	ttemp = lst->top->prev;
	btemp = lst->top;
	lst->top->next = lst->bottom;
	lst->bottom->prev = lst->top;
	lst->top->prev->next = NULL;
	lst->top->prev = NULL;
	lst->top = ttemp;
	lst->bottom = btemp;
}

void	push(t_node *to, t_node *from)
{
	int	val;

	val = to->top->val;
	node_pop(to);
	node_push(from, val);
	/*
	if (to == NULL)
		return ;	
	temp = to->top;
	to->top = to->top->prev;
	to->top->next = NULL;
	temp->prev = from->top;
	if (from->size != 0)
		from->top->next = temp;
	else
		from->bottom = temp;
	from->top = temp;
	from->top->next = NULL;
	from->size++;
	to->size--;
	*/
}

void	swap(t_node *lst)
{
	int	up;
	int	down;

	up = lst->top->val;
	down = lst->top->prev->val;
	node_pop(lst);
	node_pop(lst);
	node_push(lst, up);
	node_push(lst, down);
	/*
	t_number	*ttemp;
	t_number	*ptemp;
	t_number	*pptemp;

	if (lst == NULL || lst->bottom->next == NULL)
		return ;
	lst->top->prev->prev->next = lst->top;
	ttemp = lst->top;
	ptemp = lst->top->prev;
	pptemp = lst->top->prev->prev;
	lst->top = lst->top->prev;
	lst->top->prev = ptemp;
	lst->top->next = NULL;
	lst->top->prev = ttemp;
	lst->top->prev->next = ptemp;
	lst->top->prev->prev = pptemp;
	*/
}
