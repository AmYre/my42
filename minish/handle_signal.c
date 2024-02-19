/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:53:46 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 17:07:03 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//setup les signal handler de SIGINT = ctrl-c de maniere a afficher une nouvelle
//ligne et de SIGQUIT = ctrl-\ set a SIG_IGN qui permet d'ignorer le signal

void	handle_signal(int sign)
{
	if (sign == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	command_handler(void)
{
	static struct sigaction	handler;

	sigemptyset(&handler.sa_mask);
	handler.sa_handler = SIG_IGN;
	handler.sa_flags = SA_RESTART;
	sigaction(SIGINT, &handler, 0);
	sigaction(SIGQUIT, &handler, 0);
}

void	make_signal(void)
{
	static struct sigaction	handler;
	static struct sigaction	defaul;
	static struct sigaction	ignore;

	sigemptyset(&ignore.sa_mask);
	sigemptyset(&defaul.sa_mask);
	sigemptyset(&handler.sa_mask);
	defaul.sa_flags = 0;
	ignore.sa_flags = 0;
	handler.sa_flags = 0;
	defaul.sa_handler = SIG_DFL;
	ignore.sa_handler = SIG_IGN;
	handler.sa_handler = handle_signal;
	sigaction(SIGPIPE, &defaul, 0);
	sigaction(SIGINT, &handler, 0);
	sigaction(SIGQUIT, &ignore, 0);
}

void	default_handler(void)
{
	static struct sigaction	handler;

	sigemptyset(&handler.sa_mask);
	handler.sa_handler = SIG_DFL;
	handler.sa_flags = 0;
	sigaction(SIGINT, &handler, 0);
	sigaction(SIGQUIT, &handler, 0);
}

void	builtins_handler(void)
{
	static struct sigaction	handler;

	sigemptyset(&handler.sa_mask);
	handler.sa_handler = SIG_IGN;
	handler.sa_flags = 0;
	sigaction(SIGPIPE, &handler, 0);
	sigaction(SIGINT, &handler, 0);
	sigaction(SIGQUIT, &handler, 0);
}
