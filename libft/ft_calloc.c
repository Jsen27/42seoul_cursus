/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:58:09 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/13 16:42:09 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*temp;
	long long	total;

	total = count * size;
	if (total / count != size)
		return (NULL);
	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (count * size));
	return (temp);
}
