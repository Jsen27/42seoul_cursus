/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:04:54 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/05 13:59:04 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	int				*temp;
	unsigned int	size;

	i = 0;
	if (max < 0)
		size = -max;
	else
		size = max;
	if (min < max)
	{
		temp = (int *)malloc(sizeof(int) * (size - min));
		if (temp == 0)
			return (-1);
		*range = temp;
		while (min < max)
			temp[i++] = min++;
	}
	else
		return (0);
	return (i);
}
