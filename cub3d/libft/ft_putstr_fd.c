/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:03:16 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/13 20:48:51 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = 0;
	while (*(s + length))
		length ++;
	write(fd, s, length);
}
