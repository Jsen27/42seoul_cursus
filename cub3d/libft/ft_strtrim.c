/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:10:02 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 15:48:25 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_set(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set ++;
	}
	return (0);
}

static int	find_retstr_length(char const *s1, char const *set)
{
	int	ret_length;

	while (*s1 != '\0' && is_set(*s1, set))
		s1 ++;
	ret_length = 0;
	while (*(s1 + ret_length))
		ret_length ++;
	while (ret_length > 0)
	{
		if (!is_set(*(s1 + ret_length - 1), set))
			break ;
		ret_length --;
	}
	return (ret_length);
}

static void	assign_ptr(char *ptr, char const *s1, char const *set, int length)
{
	int	i;

	while (*s1 != '\0' && is_set(*s1, set))
		s1 ++;
	i = 0;
	while (i < length)
	{
		*(ptr + i) = *(s1 + i);
		i ++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		retstr_length;
	char	*retptr;

	retstr_length = find_retstr_length(s1, set);
	retptr = (char *)malloc(sizeof(char) * retstr_length + 1);
	if (retptr == 0)
		return (0);
	*(retptr + retstr_length) = '\0';
	assign_ptr(retptr, s1, set, retstr_length);
	return (retptr);
}
