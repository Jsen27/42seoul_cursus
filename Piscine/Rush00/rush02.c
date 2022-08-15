/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:20:36 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/21 20:20:28 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);
void	display(int *pos, char *res);

void	rush(int x, int y)
{
	char	res[4];
	int		pos[4];

	res[0] = 'A';
	res[1] = 'C';
	res[2] = 'B';
	res[3] = ' ';
	pos[2] = x;
	pos[3] = y;
	pos[1] = 0;
	while (++pos[1] <= y)
	{
		pos[0] = 0;
		while (++pos[0] <= x)
			display(pos, res);
		ft_putchar('\n');
	}
}

void	display(int *pos, char *res)
{
	if ((pos[0] == 1 && pos[1] == 1) || ((pos[0] == pos[2]) && (pos[1] == 1)))
		ft_putchar(res[0]);
	else if ((pos[1] == pos[3] && pos[0] == pos[2]))
		ft_putchar(res[1]);
	else if ((pos[1] == pos[3]) && (pos[0] == 1))
		ft_putchar(res[1]);
	else if ((pos[1] == 1) || (pos[1] == pos[3]))
		ft_putchar(res[2]);
	else if ((pos[0] == 1) || (pos[0] == pos[2]))
		ft_putchar(res[2]);
	else
		ft_putchar(res[3]);
}
