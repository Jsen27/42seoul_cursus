/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:37:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/08 13:39:52 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		blank(int a, int b);
int		check_sel(char *str);
int		checkblank(char *str);
int		ft_atoi(char *str);
int		add(int a, int b);
int		sub(int a, int b);
int		div(int a, int b);
int		mul(int a, int b);
int		mod(int a, int b);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	doop(int a, int b, int sel, int (**f)(int, int));

#endif