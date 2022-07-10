/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:13:38 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/10 16:13:38 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list  *ft_lstnew(void *content)
{
    t_list  *temp;
    
    temp = (t_list *)malloc(sizeof(t_list));
    if (!temp)
        return (NULL); 
    temp->content = content;
    temp->next = NULL;
    return (temp);
}