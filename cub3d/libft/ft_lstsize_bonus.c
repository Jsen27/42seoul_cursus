/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:35:59 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/15 16:13:28 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == 0)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst -> next;
		i ++;
	}
	return (i);
}
