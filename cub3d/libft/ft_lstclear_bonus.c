/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:51 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/15 16:57:40 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	while (tmp_lst)
	{
		del(tmp_lst->content);
		tmp_lst = tmp_lst -> next;
		free((*lst));
		*lst = tmp_lst;
	}
	*lst = 0;
}
