/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:29:12 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:37 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sr;
	unsigned int	a;

	a = 0;
	sr = (unsigned char *)s;
	while (a < n)
	{
		sr[a] = (unsigned char) c;
		a++;
	}
	s = (void *)sr;
	return (s);
}
