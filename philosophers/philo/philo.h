/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:21 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/05 16:57:15 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				cnt;
	int				finish_check;
	int				die_check;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long long		must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_m;
	pthread_mutex_t	monitor;
	pthread_mutex_t	die_m;
}t_data;

typedef struct s_philo
{
	pthread_t		pid;
	t_data			*data;
	int				num;
	int				eat_cnt;
	int				left;
	int				right;
	int				finish;
	long long		last_eat;
	pthread_mutex_t	finish_check;
}t_philo;

int			init_args(int argc, char **argv, t_data *data);
int			ft_atoi(const char *str);
int			error_exit(t_data *data, int error);
int			init_philo(t_data *data, t_philo **philo);
void		*thread_philo(void *arg);
int			philosophers(t_data *data, t_philo *philo);
long long	now_time(t_data *data);
void		print_stats(t_data *data, char *str, int n);
void		clear_sleep(long long time, t_data *data);
void		*just_one_philo(void *philo);
void		check_finish(t_data *data, t_philo *philo);

#endif