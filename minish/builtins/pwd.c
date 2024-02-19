/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:24:29 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/08 22:44:02 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(int	*error)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (*error |= PWD_ERROR);
	printf("%s\n", path);
	free(path);
	return (0);
}
