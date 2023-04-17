/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:51:14 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 10:18:40 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*retptr;

	length = 0;
	while (*(s1 + length))
		length ++;
	retptr = (char *)malloc(sizeof(char) * (length + 1));
	if (retptr == 0)
		return (0);
	*(retptr + length) = '\0';
	while (length >= 0)
	{
		*(retptr + length) = *(const char *)(s1 + length);
		length --;
	}
	return (retptr);
}
