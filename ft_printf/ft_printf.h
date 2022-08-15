/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:27:59 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/08 17:27:59 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf_ptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_printf_hex(unsigned int num, const char format);
int	ft_putpercent(void);
int	ft_printf(const char *input, ...);

#endif