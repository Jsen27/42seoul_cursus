/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:46:22 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/30 20:18:02 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *command, char *input, char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (command)
		ft_putstr_fd(command, STDERR_FILENO);
	if (input)
	{
		if (command)
			ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(input, STDERR_FILENO);
	}
	if (message)
	{
		if (command || input)
			ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	g_status.global_exit_status = 1;
}

void	system_error(char *str1, char *str2, int error_code)
{
	if (str1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		if (str1)
			ft_putstr_fd(str1, STDERR_FILENO);
		if (str2)
			ft_putstr_fd(str2, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (!str1 && str2)
	{
		printf("%s\n", str2);
	}
	exit(error_code);
}
