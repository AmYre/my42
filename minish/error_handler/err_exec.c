/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:04 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/10 19:25:58 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_exec(int err, char *str, t_save_fd *standard)
{
	restore_fd(standard, &err);
	if ((err & DUP_ERROR) == DUP_ERROR)
		printf("msh : %s : dup error\n", str);
	if ((err & PERMISSION_DENIED) == PERMISSION_DENIED)
		printf("msh : %s : permission denied\n", str);
	if ((err & FILE_NOT_EXIST) == FILE_NOT_EXIST)
		printf("msh : %s : no such file or directory\n", str);
	return (EXEC_ERROR);
}
