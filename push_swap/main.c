/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:47:18 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/20 20:57:10 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	return (0);
}