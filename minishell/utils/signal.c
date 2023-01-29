/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:35:59 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 21:24:08 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	safe_signal(int sig, void *function)
{
	if (signal(sig, function) == SIG_ERR)
		system_error("safe_signal", "signal error", 1);
}

void	sig_readline(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_status.global_exit_status = 1;
}

void	sig_fork(int mode)
{
	safe_signal(SIGINT, SIG_DFL);
	if (mode == SUBSHELL)
	{
		safe_signal(SIGQUIT, SIG_DFL);
	}
}

void	sig_process(int sig)
{
	if (sig == SIGINT)
		printf("\n");
}

void	init_signal(void)
{
	struct termios	s_term;

	if (tcgetattr(STDIN_FILENO, &s_term) == -1)
		system_error("init_signal", "tcgetattr error", 1);
	s_term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &s_term) == -1)
		system_error("init_signal", "tcsetattr error", 1);
	safe_signal(SIGINT, sig_readline);
	safe_signal(SIGQUIT, SIG_IGN);
	safe_signal(SIGTSTP, SIG_IGN);
}
