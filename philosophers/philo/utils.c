/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:12:50 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/05 17:04:29 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_time(t_data *data)
{
	struct timeval		temp;
	static long long	base_time;
	long long			res;

	pthread_mutex_lock(&data->monitor);
	if (base_time == 0)
	{
		gettimeofday(&temp, NULL);
		base_time = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	}
	gettimeofday(&temp, NULL);
	res = ((temp.tv_sec * 1000) + (temp.tv_usec / 1000) - base_time);
	pthread_mutex_unlock(&data->monitor);
	return (res);
}

void	clear_sleep(long long wait_time, t_data *data)
{
	long long	target;

	target = wait_time + now_time(data);
	while (target > now_time(data))
	{
		pthread_mutex_lock(&data->monitor);
		if (data->finish_check)
		{
			pthread_mutex_unlock(&data->monitor);
			break ;
		}
		pthread_mutex_unlock(&data->monitor);
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
	int	check;

	pthread_mutex_lock(&data->monitor);
	check = data->finish_check;
	pthread_mutex_unlock(&data->monitor);
	if (!(check))
	{
		pthread_mutex_lock(&data->print_m);
		pthread_mutex_lock(&data->die_m);
		check = data->die_check;
		pthread_mutex_unlock(&data->die_m);
		if (!check)
			printf("%lld %d %s\n", now_time(data), n, str);
		pthread_mutex_unlock(&data->print_m);
	}
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
	if (str[i] != '\0')
		return (0);
	return (ans * pm);
}
