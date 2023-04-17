/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:58:13 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/16 09:07:44 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	size_t	sub_length;
	size_t	tmp;
	char	*sub_ptr;

	str_length = 0;
	while (*(s + str_length))
		str_length ++;
	sub_length = 0;
	while (sub_length + start < str_length && sub_length < len)
		sub_length ++;
	sub_ptr = malloc(sizeof(char) * (sub_length + 1));
	if (sub_ptr == 0)
		return (0);
	*(sub_ptr + sub_length) = '\0';
	tmp = 0;
	while (tmp < sub_length)
	{
		*(sub_ptr + tmp) = *(s + start + tmp);
		tmp ++;
	}
	return (sub_ptr);
}
