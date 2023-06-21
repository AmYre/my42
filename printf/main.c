/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:00 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/21 02:50:52 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	main(void)
{
	// Basic upcdiuxX

	 char	*ptr;
	int		uint;
	int		result;

	uint = 42;
	ptr = "pointeurTest";
	printf("\nlength of format : %d", ft_printf("print me %c good %s at %p for %d person, maybe %i, but sure %u. hexa %x and %X %%", 'a', "choucreme", ptr, -28, 28, 42, uint, uint));
	printf("\n");
	result = printf("print me %c good %s at %p for %d person, maybe %i, but sure %u. hexa %x and %X %%", 'a', "choucreme", ptr, -28, 28, 42, uint, uint);
	printf("\nlength of tamrof : %d", result);

	return (0);
}

//\c not working
//\UHHHHHHHH not working
