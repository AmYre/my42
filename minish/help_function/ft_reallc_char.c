/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallc_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:20:14 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:52 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell.h"

// int	ft_realloc_tchar(t_char_flag **str, int size)
// {
// 	t_char_flag	*temp;
// 	int			i;

// 	i = 0;
// 	temp = malloc(sizeof(char) * size + 1);
// 	if (temp == 0)
// 		return (0);
// 	while ((*str)[i])
// 	{
// 		temp[i] = (*str)[i];
// 		i++;
// 	}
// 	while (i < size)
// 	{
// 		temp[i] = '0';
// 		i++;
// 	}
// 	temp[i] = '\0';
// 	if (*str != 0)
// 		free(*str);
// 	*str = temp;
// 	return (1);
// }
