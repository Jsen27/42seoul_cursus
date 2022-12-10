/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:38 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/10 16:09:24 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(long int *arr, int *stack)
{
	if (arr)
		free(arr);
	if (stack)
		free(stack);
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
	stack_b = ft_calloc(numbers + 2, sizeof(int));
	if (!stack_b)
		error_exit(NULL, stack_a);
	sort_algorithm(stack_a, stack_b, numbers);
	free(stack_a);
	free(stack_b);
	return (0);
}
