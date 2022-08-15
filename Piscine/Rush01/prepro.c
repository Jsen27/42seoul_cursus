/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myjo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:57:36 by myjo              #+#    #+#             */
/*   Updated: 2022/05/29 21:15:37 by myjo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putzero(int two_dim_ar[][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			two_dim_ar[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	constr_width(int *constr, int two_dim_ar[][6])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < 5)
	{
		two_dim_ar[i][j] = constr[j - 1];
		j++;
	}
	i = 5;
	j = 1;
	while (j < 5)
	{
		two_dim_ar[i][j] = constr[j + 3];
		j++;
	}
}

void	constr_height(int *constr, int two_dim_ar[][6])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < 5)
	{
		two_dim_ar[j][i] = constr[j + 7];
		j++;
	}
	i = 5;
	j = 1;
	while (j < 5)
	{
		two_dim_ar[j][i] = constr[j + 11];
		j++;
	}
}

int	check_av(char *str)
{
	int	i;
	int	len;
	int	cnt;

	i = 0;
	len = 0;
	cnt = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] >= '1' && str[i] <= '4')
				cnt++;
		}
		else
		{
			if (str[i - 1] == ' ' && (str[i] >= '1' && str[i] <= '4'))
				cnt++;
		}
		len++;
		i++;
	}
	if (len == 31 && cnt == 16)
		return (1);
	return (0);
}

void	map_int(char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			arr[i / 2] = str[i] - '0';
		i++;
	}
}
