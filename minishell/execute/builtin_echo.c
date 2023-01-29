/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:35:54 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 16:49:55 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	echo_option(char *str)
{
	int	i;

	if (!str || ft_strlen(str) < 2)
		return (NO);
	if (str[0] != '-' || str[1] != 'n')
		return (NO);
	i = 2;
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (NO);
		i++;
	}
	return (YES);
}

static void	setup_echo_option(int *i, int *option, char **command)
{
	int	flag;

	*i = 1;
	*option = 0;
	flag = echo_option(command[*i]);
	while (flag)
	{
		(*i)++;
		*option = 1;
		flag = echo_option(command[*i]);
	}
}

void	builtin_echo(t_list *list)
{
	int		i;
	int		option;
	char	**command;

	command = list_to_strs(list);
	if (!command)
		system_error("builtin_echo", "malloc error", 1);
	else
	{
		if (!command[1])
			printf("\n");
		else
		{
			setup_echo_option(&i, &option, command);
			while (command[i] && command[i + 1])
				printf("%s ", command[i++]);
			if (command[i])
				printf("%s", command[i]);
			if (option == 0)
				printf("\n");
		}
	}
	free_strs(command);
}
