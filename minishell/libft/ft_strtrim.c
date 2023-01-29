/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:00:44 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/15 19:48:38 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*temp;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && checkset(s1[start], set))
		start++;
	while (end > start && checkset(s1[end - 1], set))
		end--;
	temp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!temp)
		return (NULL);
	while (start < end)
		temp[i++] = s1[start++];
	temp[i] = '\0';
	return (temp);
}
