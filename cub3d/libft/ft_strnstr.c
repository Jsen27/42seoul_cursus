/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:10 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 15:49:56 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check_needle(const char *hey, const char *nee, size_t i, size_t len)
{
	int	needle_index;

	needle_index = 0;
	while (*(hey + i) != '\0' && i < len)
	{
		if (*(hey + i) != *(nee + needle_index))
		{
			break ;
		}
		if (*(nee + needle_index + 1) == '\0')
			return (1);
		i ++;
		needle_index ++;
	}
	return (0);
}

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)heystack);
	i = 0;
	while (*(heystack + i) != '\0' && i < len)
	{
		if (*(heystack + i) == *needle)
		{
			if (check_needle(heystack, needle, i, len) == 1)
				return ((char *)heystack + i);
		}
		i ++;
	}
	return (0);
}
