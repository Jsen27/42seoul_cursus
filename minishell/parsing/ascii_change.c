/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:21:05 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/29 21:51:00 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	double_quote(char *str, int i)
{
	int	j;
	int	check;

	check = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
			if (check)
				break ;
			check++;
			i--;
		}
		i++;
	}
	return (i);
}

static int	single_quote(char *str, int i)
{
	int	j;
	int	check;

	check = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str[i] = -11;
		if (str[i] == '\'')
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
			if (check)
				break ;
			check++;
			i--;
		}
		i++;
	}
	return (i);
}

static void	del_quote(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\'')
			{
				j = single_quote(str[i], j);
				continue ;
			}
			else if (str[i][j] == '\"')
			{
				j = double_quote(str[i], j);
				continue ;
			}
			j++;
		}
		i++;
	}
}

void	ascii_change(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == -10)
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
	del_quote(str);
}
