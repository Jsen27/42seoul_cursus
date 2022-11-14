/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:38 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/14 19:32:20 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	error_exit(long int *arr)
{
	if (arr)
		free(arr);
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int			numbers;
	int			*stack_a;
	int			*stack_b;
	long int	*long_arr;

	numbers = check_args(argc, argv);
	long_arr = make_array(argv, numbers);
	stack_a = make_stack(long_arr, numbers);
	stack_b = calloc(numbers + 2, sizeof(int));
	sort_algorithm(stack_a, stack_b, numbers);	
}
