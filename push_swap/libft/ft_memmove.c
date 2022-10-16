/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:39:50 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/12 14:36:21 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		i = len + 1;
		while (--i != 0)
			d[i - 1] = s[i - 1];
	}
	return (dst);
}
