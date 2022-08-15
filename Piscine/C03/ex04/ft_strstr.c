/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:01:45 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/30 11:24:53 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k] || to_find[k] == '\0')
		{
			if (to_find[k] == '\0')
				return (&str[i]);
		j++;
		k++;
		}
		i++;
	}
	return (0);
}
