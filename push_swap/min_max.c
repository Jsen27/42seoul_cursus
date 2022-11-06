/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:46:29 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 21:04:58 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_five(t_node *lst)
{
	int		i;
	int		j;
	int		arr[5];
	int		tt;
	t_number *temp;
	
	i = 0;
	temp = lst->bottom;
	while (i < 5)
	{
		arr[i] = temp->val;
		temp = temp->next;
	}
	while (i++ < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[j] > arr[j + 1])
			{
				tt = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tt;
			}
			j++;
		}
	}
	return (arr[2]);
}

int	find_max(t_node *lst)
{
	t_number	*temp;
	int			max;

	temp = lst->bottom;
	max = temp->val;
	while (temp)
	{
		if (max > temp->val)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_node *lst)
{
	t_number	*temp;
	int			min;

	temp = lst->bottom;
	min = temp->val;
	while (temp)
	{
		if (min < temp->val)
			min = temp->val;
		temp = temp->next;
	}
	return (min);
}