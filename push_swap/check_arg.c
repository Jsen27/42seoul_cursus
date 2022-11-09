/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:00 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 16:18:31 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *str)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& (str[i] != ' ' && str[i] != '-'))
			error_exit(NULL);
		else if (str[i] == '-' && (str[i - 1] != ' ' && i
				&& (str[i + 1] < '0' || str[i + 1] > '9')))
			error_exit(NULL);
		else if (str[i] == ' '
			&& (str[i + 1] != ' ' && str[i + 1]))
			numbers++;
		i++;
	}
	return (numbers);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	numbers;

	i = 1;
	numbers = 0;
	if (argc < 2)
		error_exit(NULL);
	while (argv[i])
	{
		numbers += check_string(argv[i]);
		numbers++;
		i++;
	}
	return (numbers);
}
