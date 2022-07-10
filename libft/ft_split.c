/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:15:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 20:40:31 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	count_word(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != charset && str[i + 1] == charset)
			count++;
		i++;
	}
	if (str[i - 1] != charset)
		count++;
	return (count);
}

void	copy_str(char *arr, char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != charset)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
}

char	**real_split(char **arr, char *str, char charset)
{
	int	word;
	int	i;
	int	j;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != charset)
				j++;
			arr[word] = malloc(sizeof(char) * (j + 1));
			if (!arr[word])
				return (freeall(arr));
			copy_str(arr[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	word = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (arr == 0)
		return (0);
	arr[word] = 0;
	arr = real_split(arr, s, c);
	return (arr);
}
