/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:19:44 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/05 13:59:25 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	total_len(int size, char **strs, char*sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		len += j;
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	len += (i * (size - 1));
	return (len);
}

char	*cpy_str(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	len = total_len(size, strs, sep);
	while (i < len)
	{
		k = 0;
		while (strs[j][k] != '\0')
			str[i++] = strs[j][k++];
		k = 0;
		while (sep[k] != '\0' && j < size - 1)
			str[i++] = sep[k++];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char) * 1);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (total_len(size, strs, sep) + 1));
	if (str == 0)
		return (0);
	return (cpy_str(size, strs, sep, str));
}
