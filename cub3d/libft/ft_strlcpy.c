/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:51:44 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 14:29:00 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	tmp;

	srclen = 0;
	while (*(src + srclen))
		srclen ++;
	tmp = 0;
	if (srclen + 1 < dstsize)
	{
		while (tmp <= srclen)
		{
			*(dst + tmp) = *(src + tmp);
			tmp ++;
		}
	}
	else if (dstsize != 0)
	{
		while (tmp < dstsize - 1)
		{
			*(dst + tmp) = *(src + tmp);
			tmp ++;
		}
		*(dst + tmp) = '\0';
	}
	return (srclen);
}
