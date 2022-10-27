/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:28:01 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 17:45:41 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_pushback(t_node *lst, int val)
{
	t_number	*temp;

	if (lst->size == 0)
	{
		lst->bottom = malloc(sizeof(t_number));
		lst->bottom->val = val;
		lst->top = lst->bottom;
		lst->bottom->next = NULL;
		lst->bottom->prev = NULL;
		lst->size++;
		return ;
	}
	temp = lst->bottom;
	while (temp)
		temp = temp->next;
	temp = malloc(sizeof(t_number));
	temp->val = val;
	temp->next = lst->bottom;
	temp->prev = NULL;
	lst->bottom->prev = temp;
	lst->bottom = temp;
	lst->size++;
}


void	node_push(t_node *lst, int val)
{
	t_number	*temp;

	if (lst->size == 0)
	{
		lst->bottom = malloc(sizeof(t_number));
		lst->bottom->val = val;
		lst->top = lst->bottom;
		lst->bottom->next = NULL;
		lst->bottom->prev = NULL;
		lst->size++;
		return ;
	}
	temp = lst->bottom;
	while (temp)
		temp = temp->next;
	temp = malloc(sizeof(t_number));
	temp->val = val;
	temp->next = NULL;
	temp->prev = lst->top;
	lst->top->next = temp;
	lst->top = temp;
	lst->size++;
}

void	node_popback(t_node *lst)
{
	t_number	*temp;

	if (lst->size == 0)
		return ;
	temp = lst->bottom;
	lst->bottom = lst->bottom->next;
	lst->bottom->prev = NULL;
	free(temp);
}

void	node_pop(t_node *lst)
{
	t_number	*temp;

	if (lst->size == 0)
		return ;
	temp = lst->top;
	lst->top = lst->top->prev;
	lst->size--;
	if (lst->size != 0)
		lst->top->next = NULL;
	free(temp);
}
