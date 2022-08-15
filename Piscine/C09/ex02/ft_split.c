/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:25:47 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/06 16:58:18 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((check_charset(str[i + 1], charset) == 1)
			&& (check_charset(str[i], charset) == 0))
			count++;
		i++;
	}
	return (count);
}

void	copy_str(char *arr, char *str, char *charset)
{
	int	i;

	i = 0;
	while (check_charset(str[i], charset) == 0)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
}

void	real_split(char **arr, char *str, char *charset)
{
	int	word;
	int	i;
	int	j;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (check_charset(str[i + j], charset) == 0)
				j++;
			arr[word] = malloc(sizeof(char) * (j + 1));
			copy_str(arr[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		word;

	word = count_word(str, charset);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (arr == 0)
		return (0);
	arr[word] = 0;
	real_split(arr, str, charset);
	return (arr);
}
