/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myjo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:23:50 by myjo              #+#    #+#             */
/*   Updated: 2022/05/31 14:19:59 by myjo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	dfs_loop(int x, int y, int l, int ar[][6]);
void	putzero(int two_dim_ar[][6]);
void	constr_width(int *constr, int two_dim_ar[][6]);
void	constr_height(int *constr, int two_dim_ar[][6]);
int		check_av(char *str);
void	map_int(char *str, int *arr);
void	print_ans(int ar[][6]);
int		last_x(int table[][6], int x, int y, int len);
int		last_y(int table[][6], int x, int y, int len);
int		check_x(int table[][6], int x, int y);
int		check_y(int table[][6], int x, int y);
int		check2(int x, int y, int z, int table[][6]);
int		check1(int i, int j, int z, int table[][6]);
void	dfs(int x, int y, int l, int ar[][6]);

int	main(int ac, char **av)
{
	int	cnstr[16];
	int	two_dim_ar[6][6];

	if (ac == 2)
	{
		if (check_av(av[1]))
		{
			map_int(av[1], cnstr);
			putzero(two_dim_ar);
			constr_width(cnstr, two_dim_ar);
			constr_height(cnstr, two_dim_ar);
			dfs(1, 1, 4, two_dim_ar);
		}
	}
	return (0);
}
