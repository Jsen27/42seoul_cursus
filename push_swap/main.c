/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:47:18 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/16 21:28:59 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	
	a = malloc(sizeof(t_node));
	b = malloc(sizeof(t_node));
	if (!a || !b)
		return (0);
	node_init(a, argc, argv);
	return (0);
}