/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:24:31 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:21:53 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;
	unsigned char	*s;
	unsigned char	*sr;

	x = 0;
	s = (unsigned char *)s1;
	sr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s[x] == sr[x] && x < (unsigned int)n - 1)
		x++;
	return (s[x] - sr[x]);
}
