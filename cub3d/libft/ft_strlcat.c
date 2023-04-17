/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:52:00 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 15:06:46 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	tmp;

	srclen = 0;
	dstlen = 0;
	while (*(src + srclen))
		srclen ++;
	while (*(dst + dstlen) && dstlen < dstsize)
		dstlen ++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	tmp = -1;
	if (srclen < dstsize - dstlen)
	{
		while (++ tmp <= srclen)
			*(dst + dstlen + tmp) = *(src + tmp);
	}
	else
	{
		while (++ tmp < dstsize - dstlen - 1)
			*(dst + dstlen + tmp) = *(src + tmp);
		*(dst + dstlen + tmp) = '\0';
	}
	return (dstlen + srclen);
}
