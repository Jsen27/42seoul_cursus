/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:34:30 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 18:08:03 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if (src < dst && src + len >= dst)
	{
		while (i < len)
		{
			*(char *)(dst + len - i - 1) = *(char *)(src + len - i - 1);
			i ++;
		}
		return (dst);
	}
	while (i < len)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i ++;
	}
	return (dst);
}
