/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:45:32 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/23 21:35:54 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_len(src));
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (ft_len(src));
}
