/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:28:01 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/21 16:24:12 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = malloc(sizeof(t_number));
	temp->next->val = val;
	temp->next->next = NULL;
	temp->prev = lst->top;
	lst->top = temp->next;
	lst->size++;
}

void	node_pop(t_node *lst)
{
	t_number	*temp;

	temp = lst->top;
	lst->top->prev->next = NULL;
	lst->top = lst->top->prev;
	lst->size--;
	free(temp);
}
