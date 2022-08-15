/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmyung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:56:19 by jmyung            #+#    #+#             */
/*   Updated: 2022/05/29 21:04:56 by myjo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check1(int i, int j, int z, int table[][6])
{
	int	x_idx;
	int	y_idx;

	x_idx = 1;
	y_idx = 1;
	while (x_idx < j)
	{
		if (table[i][x_idx] == z)
			return (0);
		x_idx++;
	}
	while (y_idx < i)
	{
		if (table[y_idx][j] == z)
			return (0);
		y_idx++;
	}
	return (1);
}
