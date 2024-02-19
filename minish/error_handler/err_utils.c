/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:30:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/17 16:49:40 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	malloc_err(t_commands *p)
{
	clean_env(p->env);
	rl_clear_history();
	printf("MALLOC ERROR.\n");
	exit(MALLOC_ERROR);
}

void	redirect_err(t_commands *p)
{
	(void)p;
	printf("ambiguous redirect\n");
}

void	exit_d(t_commands *p)
{
	clean_env(p->env);
	rl_clear_history();
	printf("exit\n");
	exit(0);
}

void	erno_d(t_commands *p)
{
	clean_env(p->env);
	rl_clear_history();
	perror("msh:");
	exit(errno);
}

void	dup_d(t_commands *p)
{
	clean_env(p->env);
	rl_clear_history();
	write(2, "dup_error\n", 10);
	exit(DUP_ERROR);
}
