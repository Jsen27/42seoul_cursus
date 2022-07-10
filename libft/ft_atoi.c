/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:53:56 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/08 15:56:36 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkblank(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
		{
			i++;
			continue ;
		}
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	pm;
	int	ans;

	i = checkblank(str);
	pm = 1;
	ans = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return (ans * pm);
}
