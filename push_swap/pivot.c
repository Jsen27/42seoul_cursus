/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:14 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/25 20:28:13 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int pivot;
	int	temp;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (right > i)
		quick_sort(arr, i, right);
}

void	find_pivot(t_node *lst, int *pivot_small, int *pivot_big)
{
	int	arr[lst->size];
	int	i;
	t_number *temp;

	i = 0;
	temp = lst->bottom;
	while (temp)
	{
		arr[i] = temp->val;
		temp = temp->next;
		i++;
	}
	quick_sort(arr, 0, lst->size - 1);
	*pivot_small = arr[(lst->size - 1) / 3];
	*pivot_big = arr[((lst->size - 1) * 2) / 3];
	i = 0;
	printf("small = %d, big = %d size = %d\n", *pivot_small, *pivot_big, lst->size);
	while (i < lst->size)
		printf("%d\n", arr[i++]);
}
