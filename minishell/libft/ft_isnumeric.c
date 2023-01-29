/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:23:21 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/17 13:36:19 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumeric(char *s)
{
	int						i;
	int						sign;
	unsigned long long		num;

	if (!ft_isdigit(s[0]) && s[0] != '-' && s [0] != '+')
		return (0);
	i = 1;
	while (s[i] != '\0')
		if (ft_isdigit(s[i++]) == 0)
			return (0);
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign *= -1;
	num = 0;
	while (s[i] >= '0' && s[i] <= '9')
		num = num * 10 + (s[i++] - '0');
	if ((num > 9223372036854775807 && sign == 1) \
		|| (num > 9223372036854775808ULL && sign == -1))
		return (0);
	return (1);
}
