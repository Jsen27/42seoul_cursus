/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:44:20 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/10 16:44:20 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *temp;
    t_list  *result;

    if (lst == NULL || f = NULL)
        return (NULL);
    result = NULL;
    while (lst)
    {
        temp = ft_lstnew((*f)(lst->content));
        if (temp)
        {
            ft_lstclear(&result, del);
            return (NULL);
        }
        ft_lstadd_back(&result, temp);
        temp = temp->next;
        lst = lst.next;
    }
    return (result);
}
