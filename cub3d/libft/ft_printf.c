/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:28:20 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/17 21:42:19 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft.h"

void	categorize_type(const char *format, int *length, va_list ap)
{
	char	type;

	type = *format;
	if (type == 'c' || type == 'd' || type == 'i')
		check_type1(type, length, ap);
	else if (type == 'x' || type == 'X')
		check_type2(type, length, ap);
	else if (type == '%' || type == 'u')
		check_type3(type, length, ap);
	else if (type == 's')
		check_type4(type, length, ap);
	else if (type == 'p')
		check_type5(type, length, ap);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			categorize_type(format, &length, ap);
		}
		else
		{
			write(1, format, 1);
			length ++;
		}
		format ++;
	}
	va_end(ap);
	return (length);
}
