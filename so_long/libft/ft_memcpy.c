/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:26:44 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/11 16:38:04 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;

	i = 0;
	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dest[i] = sour[i];
		i++;
	}
	return (dst);
}
