/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:46:53 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/15 16:37:00 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tmp_lst = *lst;
	while (tmp_lst->next)
	{
		tmp_lst = tmp_lst -> next;
	}
	tmp_lst->next = new;
}
