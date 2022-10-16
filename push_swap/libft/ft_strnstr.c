/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:28:32 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/12 15:57:30 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (haystack[i] && len >= needle_len)
	{
		if (!ft_strncmp((char *)haystack + i, (char *)needle, needle_len))
			return ((char *)haystack + i);
		i++;
		len--;
	}
	return (NULL);
}
