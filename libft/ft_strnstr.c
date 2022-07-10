/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:28:32 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 17:09:17 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] != '\0' && i < len - ft_strlen(needle))
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] || needle[k] == '\0')
		{
			if (needle[k] == '\0')
				return (&haystack[j]);
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
