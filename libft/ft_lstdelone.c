/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:33:59 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/10 16:33:59 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst == NULL || del == NULL)
        return ;
    del(lst->content);
    free(lst);
}
