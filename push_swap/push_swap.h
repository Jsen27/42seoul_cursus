/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:59:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/27 17:46:31 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_number t_number;

typedef struct s_number
{
	int			val;
	t_number	*prev;
	t_number	*next;
}				t_number;

typedef struct s_node
{
	int			size;
	t_number	*top;
	t_number	*bottom;
}				t_node;

typedef struct s_val
{
	int	ra;
	int	pa;
	int	pb;
	int	rb;
	int	small;
	int	big;
}				t_val;

void	node_push(t_node *lst, int val);
void	node_pop(t_node *lst);
void	node_init(t_node *lst, t_node *b, int argc, char **argv);
void	swap(t_node *lst);
void	push(t_node *to, t_node *from);
void	rotate(t_node *lst);
void	re_rotate(t_node *lst);
int		print_error(int type);
void	node_check(t_node *lst);
void	find_pivot(t_node *lst, int *pivot_small, int *pivot_big);
void	stack_sort(t_node *a, t_node *b);
void	node_pushback(t_node *lst, int val);
void	node_popback(t_node *lst);
void	a_to_b(t_node *a, t_node *b, int r);
