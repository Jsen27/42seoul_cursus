/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/05 13:58:57 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (max < 0)
		size = -max;
	else
		size = max;
	if (min < max)
	{
		arr = (int *)malloc(sizeof(int) * (size - min));
		if (arr == 0)
			return (0);
		while (min < max)
			arr[i++] = min++;
	}
	else
		return (0);
	return (arr);
}
