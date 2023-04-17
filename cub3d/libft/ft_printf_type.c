/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:05:26 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/17 21:42:07 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft.h"

void	check_type1(char format_type, int *length, va_list ap)
{
	char	tmp_c;
	int		tmp_i;

	if (format_type == 'c')
	{
		tmp_c = va_arg(ap, int);
		write(1, &tmp_c, 1);
		(*length)++;
	}
	else if (format_type == 'd')
	{
		tmp_i = va_arg(ap, int);
		*length = *length + find_int_digit(tmp_i);
		ft_putnbr_fd(tmp_i, 1);
	}
	else if (format_type == 'i')
	{
		tmp_i = va_arg(ap, int);
		*length = *length + find_int_digit(tmp_i);
		ft_putnbr_fd(tmp_i, 1);
	}
}

void	check_type2(char format_type, int *length, va_list ap)
{
	unsigned int	tmp_ui;

	if (format_type == 'x')
	{
		tmp_ui = va_arg(ap, int);
		*length = *length + put_hexnbr(tmp_ui);
	}
	else if (format_type == 'X')
	{
		tmp_ui = va_arg(ap, int);
		*length = *length + put_large_hexnbr(tmp_ui);
	}
}

void	check_type3(char format_type, int *length, va_list ap)
{
	unsigned long long	tmp_ull;

	if (format_type == '%')
	{
		write(1, &format_type, 1);
		(*length)++;
	}
	if (format_type == 'u')
	{
		tmp_ull = va_arg(ap, int);
		*length = *length + find_unsigned_int_digit(tmp_ull);
		ft_put_unsigned_nbr_fd(tmp_ull, 1);
	}
}

void	check_type4(char format_type, int *length, va_list ap)
{
	char	*tmp_p;

	if (format_type == 's')
	{
		tmp_p = va_arg(ap, char *);
		if (tmp_p == 0)
		{
			write(1, "(null)", 6);
			(*length) += 6;
		}
		else
		{
			write(1, tmp_p, ft_strlen(tmp_p));
			(*length) = (*length) + ft_strlen(tmp_p);
		}
	}
}

void	check_type5(char format_type, int *length, va_list ap)
{
	char	*tmp_p;

	if (format_type == 'p')
	{
		tmp_p = va_arg(ap, void *);
		write(1, "0x", 2);
		(*length) += 2;
		if (tmp_p == 0)
		{
			write(1, "0", 1);
			(*length) += 1;
		}
		else
			(*length) = (*length) + put_hexnbr((unsigned long long)tmp_p);
	}
}
