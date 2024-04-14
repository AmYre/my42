/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:54 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 18:35:23 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = 0;
	while (lst != NULL)
	{
		temp = ft_lstnew((f)(lst -> content));
		if (!temp)
		{
			ft_lstdelone(temp, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		temp = temp -> next;
		lst = lst -> next;
	}
	return (new);
}
