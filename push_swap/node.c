/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:28:01 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/20 20:22:05 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_b(t_node *lst)
{
	lst->bottom = NULL;
	lst->top = NULL;
	lst->size = 0;
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

void	node_init(t_node *lst, t_node *b, int argc, char **argv)
{
	t_number	*temp;
	t_number	*t_prev;

	temp = malloc(sizeof(t_number));
	temp->val = ft_atoi(argv[--argc]);
	temp->prev = NULL;
	lst->bottom = temp;
	lst->size = 1;
	while (0 < --argc)
	{
		t_prev = temp;
		temp->next = malloc(sizeof(t_number));
		temp = temp->next;
		temp->prev = t_prev;
		temp->val = ft_atoi(argv[argc]);
		lst->size++;
	}
	temp->next = NULL;
	lst->top = temp;
	make_b(b);
}