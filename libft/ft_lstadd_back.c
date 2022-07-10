/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:28:19 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/10 16:28:19 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;

    if (lst == NULL || new == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    temp = ft_lstlast(*lst);
    new->next = temp->next;
    temp->next = new;
}
