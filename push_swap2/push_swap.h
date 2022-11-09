/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:50 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 16:54:15 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void		error_exit(long int *arr);
void		mov_down(int *stack);
void		mov_up(int *stack);
void		ft_push(int *to, int *from, char type);
void		ft_swap(int *stack, char type);
void		ft_rotate(int *stack, char type);
void		ft_re_rotate(int *stack, char type);
int			*make_stack(long int *arr, int numbers);
int			check_args(int argc, char **argv);
long int	*make_array(char **argv,int numbers);
