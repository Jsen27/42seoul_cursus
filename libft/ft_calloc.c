/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:58:09 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 20:16:44 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	temp = malloc(count * size);
	if (!temp)
		return (0);
	while (i < count)
		temp[i++] = 0;
	temp[i] = 0;
	return (temp);
}
