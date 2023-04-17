/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:54:06 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/11 09:37:59 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	assign_joinstr(char *joinstr, char const *s1, char const *s2)
{
	int		tmp;
	int		s1_length;
	int		s2_length;

	s1_length = 0;
	s2_length = 0;
	while (*(s1 + s1_length))
		s1_length ++;
	while (*(s2 + s2_length))
		s2_length ++;
	tmp = 0;
	while (tmp < s1_length)
	{
		*(joinstr + tmp) = *(s1 + tmp);
		tmp ++;
	}
	while (tmp < s1_length + s2_length)
	{
		*(joinstr + tmp) = *(s2 + tmp - s1_length);
		tmp ++;
	}
	*(joinstr + tmp) = '\0';
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	int		s1_length;
	int		s2_length;
	int		tmp;

	s1_length = 0;
	s2_length = 0;
	while (*(s1 + s1_length))
		s1_length ++;
	while (*(s2 + s2_length))
		s2_length ++;
	joinstr = (char *)malloc(s1_length + s2_length + 1);
	if (joinstr == 0)
		return (0);
	tmp = 0;
	assign_joinstr(joinstr, s1, s2);
	return (joinstr);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	size_t	sub_length;
	size_t	tmp;
	char	*sub_ptr;

	if (s == 0)
		return (0);
	str_length = 0;
	while (*(s + str_length))
		str_length ++;
	sub_length = 0;
	while (sub_length + start < str_length && sub_length < len)
		sub_length ++;
	sub_ptr = malloc(sizeof(char) * (sub_length + 1));
	*(sub_ptr + sub_length) = '\0';
	tmp = 0;
	while (tmp < sub_length)
	{
		*(sub_ptr + tmp) = *(s + start + tmp);
		tmp ++;
	}
	return (sub_ptr);
}

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	if (s == 0)
		return (0);
	length = 0;
	while (*(s + length) != 0)
		length ++;
	return (length);
}
