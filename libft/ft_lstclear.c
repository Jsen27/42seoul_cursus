/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:36:35 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/10 16:36:35 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *cur;

    if (lst == NULL || del == NULL)
        return ;
    while (*lst)
    {
        cur = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = cur;
    }
    *lst = NULL;
}
