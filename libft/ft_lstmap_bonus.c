/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:38:54 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/17 14:40:25 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*current;

	if (!lst)
		return (0);
	n_lst = ft_lstnew(f(lst->content));
	if (!n_lst)
		return (0);
	current = n_lst;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!current->next)
		{
			ft_lstclear(&n_lst, del);
			return (0);
		}
		current = current->next;
		lst = lst->next;
	}
	return (n_lst);
}
