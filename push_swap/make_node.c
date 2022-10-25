/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:23:37 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/25 16:42:27 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	arr_check(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] == arr[j + 1])
				print_error(1);
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				cnt++;
			}
			j++;
		}
		i++;
	}
	if (cnt == 0)
		print_error(1);
}

void	node_check(t_node *lst)
{
	int			arr[lst->size];
	t_number	*temp;
	size_t		i;

	i = 0;
	temp = lst->bottom;
	while (temp)
	{
		arr[i] = temp->val;
		temp = temp->next;
		i++;
	}
	arr_check(arr, lst->size);
}

static void	make_b(t_node *lst)
{
	lst->bottom = NULL;
	lst->top = NULL;
	lst->size = 0;
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
