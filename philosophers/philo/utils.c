/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:12:50 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/24 20:49:14 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_time(void)
{
	struct timeval		temp;
	static long long	base_time;

	if (base_time == 0)
	{
		gettimeofday(&temp, NULL);
		base_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	}
	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000) - base_time);
}

void	clear_sleep(long long wait_time)
{
	long long	target;

	target = wait_time + now_time();
	while (target > now_time())
	{
		usleep(100);
	}
}

static size_t	checkblank(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
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

void	print_stats(t_data *data, char *str, int n)
{
	pthread_mutex_lock(&data->print_m);
	printf("%lldms %d %s\n", now_time(), n, str);
	pthread_mutex_unlock(&data->print_m);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		pm;
	long	ans;

	i = checkblank((char *)str);
	pm = 1;
	ans = 0;
	if (str[i] == '-')
		pm *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		if (ans > 2147483647 && pm == 1)
			return (-1);
		if (ans > 2147483648 && pm == -1)
			return (0);
		i++;
	}
	return (ans * pm);
}
