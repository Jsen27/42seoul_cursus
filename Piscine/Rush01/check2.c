/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmyung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:59:18 by jmyung            #+#    #+#             */
/*   Updated: 2022/05/31 14:17:47 by myjo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_y(int table[][6], int x, int y);
int	check_x(int table[][6], int x, int y);
int	last_x(int table[][6], int x, int y, int len);
int	last_y(int table[][6], int x, int y, int len);

int	check2(int x, int y, int z, int table[][6])
{
	int	len;

	table[x][y] = z;
	len = 4;
	if (!check_y(table, x, y))
		return (0);
	if (!check_x(table, x, y))
		return (0);
	if (y == len)
		if (!last_y(table, x, y, len))
			return (0);
	if (x == len)
		if (!last_x(table, x, y, len))
			return (0);
	return (1);
}

int	check_y(int table[][6], int x, int y)
{
	int	y_idx;
	int	cnt;
	int	temp;

	y_idx = 1;
	cnt = 0;
	temp = 0;
	while (y_idx <= y)
	{
		if (table[x][y_idx] > temp)
		{
			cnt++;
			temp = table[x][y_idx];
		}
		y_idx++;
	}
	if (cnt > table[x][0])
		return (0);
	return (1);
}

int	check_x(int table[][6], int x, int y)
{
	int	x_idx;
	int	cnt;
	int	temp;

	x_idx = 1;
	cnt = 0;
	temp = 0;
	while (x_idx <= x)
	{
		if (table[x_idx][y] > temp)
		{
			cnt++;
			temp = table[x_idx][y];
		}
		x_idx++;
	}
	if (cnt > table[0][y])
		return (0);
	return (1);
}

int	last_y(int table[][6], int x, int y, int len)
{
	int	y_idx;
	int	cnt;
	int	temp;

	y_idx = y;
	cnt = 0;
	temp = 0;
	while (y_idx >= 1)
	{
		if (table[x][y_idx] > temp)
		{
			cnt++;
			temp = table[x][y_idx];
		}
		y_idx--;
	}
	if (cnt != table[x][len + 1])
		return (0);
	return (1);
}

int	last_x(int table[][6], int x, int y, int len)
{
	int	x_idx;
	int	cnt;
	int	temp;

	x_idx = x;
	cnt = 0;
	temp = 0;
	while (x_idx >= 1)
	{
		if (table[x_idx][y] > temp)
		{
			cnt++;
			temp = table[x_idx][y];
		}
		x_idx--;
	}
	if (cnt != table[len + 1][y])
		return (0);
	return (1);
}
