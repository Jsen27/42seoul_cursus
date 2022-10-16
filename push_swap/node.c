/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:28:01 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/16 21:29:02 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_push(t_node *lst, int val)
{
	t_number	*temp;
	
	temp = malloc(sizeof(t_number));
	temp->prev = lst->top;
	temp->next = NULL;
	temp->val = val;
	lst->top = temp;
	lst->size++;
}

void	node_pop(t_node *lst)
{
	t_number	*temp;

	temp = lst->top;
	lst->top = lst->top->prev;
	lst->size--;
	free(temp);
}

void	node_init(t_node *lst, int argc, char **argv)
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
}