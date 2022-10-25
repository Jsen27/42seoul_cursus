/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:47:18 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/21 16:51:05 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int type)
{
	if (type == 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_number *temp;

	a = malloc(sizeof(t_node));
	b = malloc(sizeof(t_node));
	if (!a || !b)
		return (0);
	node_init(a, b, argc, argv);
	node_check(a);
	
	
	temp = a->bottom;
	while (temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
	return (0);
}