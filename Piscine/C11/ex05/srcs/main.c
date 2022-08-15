/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:49:51 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/08 23:35:24 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		blank(int a, int b);
int		add(int a, int b);
int		sub(int a, int b);
int		div(int a, int b);
int		mul(int a, int b);
int		mod(int a, int b);
int		check_sel(char *str);
int		ft_atoi(char *str);
void	doop(int a, int b, int sel, int (**f)(int, int));

int	main(int argc, char **argv)
{
	int	sel;
	int	(*f[6])(int, int);
	int	a;
	int	b;

	f[0] = blank;
	f[1] = add;
	f[2] = sub;
	f[3] = div;
	f[4] = mul;
	f[5] = mod;
	if (argc != 4)
		return (0);
	sel = check_sel(argv[2]);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	doop(a, b, sel, f);
	write(1, "\n", 1);
	return (0);
}
