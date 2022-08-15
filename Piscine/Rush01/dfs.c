/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myjo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:05:20 by myjo              #+#    #+#             */
/*   Updated: 2022/05/31 14:19:49 by myjo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_abc;
void		dfs_loop(int x, int y, int l, int ar[][6]);
void		print_ans(int ar[][6]);
int			last_x(int table[][6], int x, int y, int len);
int			last_y(int table[][6], int x, int y, int len);
int			check_x(int table[][6], int x, int y);
int			check_y(int table[][6], int x, int y);
int			check2(int x, int y, int z, int table[][6]);
int			check1(int i, int j, int z, int table[][6]);

void	dfs(int x, int y, int l, int ar[][6])
{
	int	i;

	g_abc = 0;
	i = 1;
	if (x == l + 1 && y == 1)
	{
		print_ans(ar);
		g_abc = 1;
		return ;
	}
	else
	{
		while (i < l + 1)
		{
			if (g_abc == 1)
				return ;
			if (check1(x, y, i, ar) && check2(x, y, i, ar))
			{
				ar[x][y] = i;
				dfs_loop(x, y, l, ar);
				ar[x][y] = 0;
			}
			i++;
		}
	}
}

void	dfs_loop(int x, int y, int l, int ar[][6])
{
	if (y == l)
	{
		dfs(x + 1, 1, l, ar);
	}
	else
	{
		dfs(x, y + 1, l, ar);
	}
}

void	print_ans(int ar[][6])
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			c = ar[i][j] + '0';
			write(1, &c, 1);
			if (j != 4)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
