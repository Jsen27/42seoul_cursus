/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:04:49 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/13 15:31:49 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char) c;
	while (s[i])
		i++;
	if (temp == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == temp)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
