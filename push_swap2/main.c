/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:38 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 14:40:44 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(long int *arr)
{
	if (arr)
		free(arr);
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	numbers;
	long int	*long_arr;

	numbers = check_args(argc, argv);
	long_arr = make_array(argv, numbers);
}