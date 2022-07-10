/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:13:20 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 20:00:18 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strdup(const char *s1)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[i])
		len++;
	temp = malloc(sizeof(char) * len);
	if (!temp)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}
