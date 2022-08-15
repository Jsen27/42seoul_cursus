/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:39:27 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/21 16:59:31 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	mybox(char* c, int* pos, int x, int y);

void	rush(int x, int y)
{
	char	c[4];
	int	pos[2];

	c[0] = 'o';
	c[1] = '-';
	c[2] = '|';
	c[3] = ' ';
	pos[0] = 1;
	pos[1] = 1;
	while (!((pos[0] == x +1) && (pos[1] == y)))
	{
		if(pos[0] == x + 1)
		{
			pos[1]++;
			pos[0] = 1;
			ft_putchar('\n');
		}
		mybox(c, pos, x, y);
		pos[0]++;
	}
}

void	mybox(char* c, int* pos, int x, int y)
{
	if ((pos[0] == 1 && pos[1] == 1) || ((pos[0] == x) && (pos[1] == 1)))
	{
		ft_putchar(c[0]);
	}
	else if(pos[1] == 1)
	{
		ft_putchar(c[1]);
	}
	else if(((pos[1] == y) && (pos[0] == 1)) || ((pos[1] == y) && (pos[0] == x)))
	{
		ft_putchar(c[0]);
	}
	else if(pos[1] == y)
	{
		ft_putchar(c[1]);
	}
	else if((pos[0] == 1) || (pos[0] == x))
	{
		ft_putchar(c[2]);
	}
	else
	{
		ft_putchar(c[3]);
	}
}
