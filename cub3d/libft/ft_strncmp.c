/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:04:01 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/10 17:23:37 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) != 0 || *(s2 + i) != 0) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i ++;
	}
	return (0);
}
