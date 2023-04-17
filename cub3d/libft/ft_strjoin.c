/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:44 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 15:50:10 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	assign_joinstr(char *joinstr, char const *s1, char const *s2)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
