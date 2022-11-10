/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:50 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/10 16:54:15 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void		error_exit(long int *arr);
void		mov_down(int *stack);
void		mov_up(int *stack);
void		ft_push(int *to, int *from, char type);
void		ft_swap(int *stack, char type);
void		ft_rotate(int *stack, char type);
void		ft_re_rotate(int *stack, char type);
int			*make_stack(long int *arr, int numbers);
int			check_args(int argc, char **argv);
void		sort_algorithm(int *stack_a, int *stack_b, int numbers);
void		sort_min(int *stack_a, int *stack_b, int max);
void		sort_reverse(int *stack_a, int *stack_b);
void		sort_ten(int *stack_a, int *stack_b);
void		sort_radix(int *stack_a, int *stack_b, int numbers);
long int	*make_array(char **argv, int numbers);
int			check_sort(int *stack_a, int numbers);
int			check_three(int *stack);

#endif