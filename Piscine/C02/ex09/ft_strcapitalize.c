/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:30:11 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/23 21:34:02 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	check(char *str, int i)
{
	if (!(str[i - 1] >= 'A' && str[i -1] <= 'Z'))
	{
		if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
		{
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] -= 32;
					return ;
				}
			}
		}
	}
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
				str[i] += 32;
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				str[i] += 32;
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
				str[i] += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		check(str, i);
		i++;
	}
	return (str);
}
