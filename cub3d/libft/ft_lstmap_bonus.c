/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:01:57 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/17 09:49:49 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	free_all_lst(t_list *start_lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	while (start_lst != (t_list *)0)
	{
		tmp_lst = start_lst;
		start_lst = tmp_lst -> next;
		del(tmp_lst -> content);
		free(tmp_lst);
	}
	return ;
}

static void	go(t_list **p1, t_list **al_ptr, t_list **lst, void *(*f)(void *))
{
		(*p1) = (*al_ptr);
		(*p1)->content = f((*lst)->content);
		(*p1)->next = (void *)(0);
		(*lst) = (*lst)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_lst;
	t_list	*tmp_ptr;
	t_list	*al_ptr;

	if (lst == 0)
		return (0);
	start_lst = (t_list *)(malloc(sizeof(t_list)));
	if (start_lst == 0)
		return (0);
	go(&tmp_ptr, &start_lst, &lst, f);
	while (lst)
	{
		al_ptr = (t_list *)(malloc(sizeof(t_list)));
		if (al_ptr == (t_list *)(0))
		{
			free_all_lst(start_lst, del);
			return (0);
		}
		tmp_ptr -> next = al_ptr;
		go(&tmp_ptr, &al_ptr, &lst, f);
	}
	tmp_ptr -> next = 0;
	return (start_lst);
}
