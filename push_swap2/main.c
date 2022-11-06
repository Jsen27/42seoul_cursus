/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:12:38 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/06 23:29:38 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_overlap(long int *arr, int numbers)
{
	int	i;
	int	j;

	i = 0;
	while (i < numbers - 1)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				error_exit(arr);
			j++;
		}
		i++;
	}
}

int str_to_longarr_minus(long int *arr, char *str, int i, int j)
{
	int	len;

	len = 0;
	while (str[i] != ' ' && str[i])
	{
		len++;
		if (len > 10)
			error_exit(arr);
		arr[*j] += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			arr[*j] *= 10;
		i++;
	}
	arr[*j] *= -1;
	if (arr[j] < 2147483648)
		error_exit(arr);
	*j += 1;
	if (!str[i])
		return (i - 1);
	return (i);
}

int	str_to_longarr(long int *arr, char *str, int i, int *j)
{
	int	len;

	len = 0;
	while (str[i] != ' ' && str[i])
	{
		len++;
		if (len > 10)
			error_exit(arr);
		arr[*j] += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			arr[*j] *= 10;
		i++;
	}
	if (arr[j] > 2147483647)
		error_exit(arr);
	*j += 1;
	if (!str[i])
		return (i - 1);
	return (i);
}

void	make_longarr(long int *arr, char *str, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i = str_to_longarr_minus(arr, str, i, j);
		else if (str[i] >= '0' && str[i] <= '9')
			i = str_to_longarr(arr, str, i, j);
		i++;
	}
}

long int	*argv_to_longarr(char **argv,int numbers)
{
	long int	*arr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	arr = ft_calloc(numbers + 1, sizeof(long int));
	while (argv[i++])
		make_longarr(arr, argv[i], &j);
	i = 0;
	while (i < numbers)
	check_overlap(arr, numbers);
}

static int	check_string(char *str)
{
	int	i;
	int numbers;

	i = 0;
	numbers = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') &&
			(str[i] != ' ' && str[i] != '-'))
			error_exit(NULL);
		else if (str[i] == '-' && (str[i - 1] != ' '&& i
			&& (str[i + 1] < '0' || str[i + 1] > '9')))
			error_exit(NULL);
		else if (str[i] == ' ' &&
			(str[i + 1] != ' ' && str[i + 1]))
			numbers++;
		i++;
	}
	return (numbers);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int numbers;

	i = 0;
	numbers = 0;
	if (argc < 2)
		error_exit(NULL);
	while (argv[i])
	{
		numbers += check_string(argv[i]);
		numbers++;
	}
	return (numbers);
}

void	error_exit(long int *arr)
{
	if (arr)
		free(arr);
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	numbers;
	long int	*long_arr;

	numbers = check_args(argc, argv);
	long_arr = argv_to_longarr(argv, numbers);
}