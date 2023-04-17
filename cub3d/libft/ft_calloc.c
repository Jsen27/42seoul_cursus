/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:33:36 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/17 14:41:11 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	while (i < size * count)
	{
		*(char *)(ptr + i) = '\0';
		i ++;
	}
	return (ptr);
}
