/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:57:59 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 20:49:21 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (!s)
		return (0);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	start--;
	while (i < len)
	{
		temp[i++] = s[start++];
	}
	temp[i] = 0;
	return (temp);
}
