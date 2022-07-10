/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:46:51 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 19:57:47 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	while (i < ft_strlen(s1))
		temp[i++] = s1[j++];
	j = 0;
	while (i < len)
		temp[i++] = s2[j++];
	temp[i] = 0;
	return (temp);
}
