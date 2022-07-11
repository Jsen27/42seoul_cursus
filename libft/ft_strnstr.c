/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:28:32 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/11 19:51:44 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!ft_strlen(needle) || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < len - ft_strlen(needle))
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] || needle[k] == '\0')
		{
			if (needle[k] == '\0')
				return ((char *)haystack + i);
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}
