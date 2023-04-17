/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:20:07 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 13:32:38 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		check_found;

	check_found = -1;
	i = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) == (char)c)
		{
			check_found = i;
		}
		i ++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	if (check_found != -1)
		return ((char *)(s + check_found));
	return (0);
}
