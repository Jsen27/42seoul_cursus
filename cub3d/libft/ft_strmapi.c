/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:28:12 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/17 11:09:17 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	str_length;
	char			*retptr;

	str_length = 0;
	while (*(s + str_length))
		str_length ++;
	retptr = (char *)malloc(sizeof(char) * (str_length + 1));
	if (retptr == 0)
		return (0);
	*(retptr + str_length) = '\0';
	while ((int)--str_length >= 0)
		*(retptr + str_length) = f(str_length, *(s + str_length));
	return (retptr);
}
