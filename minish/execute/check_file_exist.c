/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:58:46 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/09 14:53:14 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_file_exist(char *str, t_save_fd *standard)
{
	if (access(str, F_OK))
	{
		err_exec(FILE_NOT_EXIST, str, standard);
		free(str);
		return (EXEC_ERROR);
	}
	return (0);
}
