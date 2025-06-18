/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:24:56 by jockova           #+#    #+#             */
/*   Updated: 2025/03/17 14:34:14 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A new pointer created
	t_list *next_node;
In while loop: This new_node will be the same as *lst->next pointer 
pointing to the second node of lst:
	*next_node = *lst->next;
Then we can delete the first node of lst
	ft_lstdelone(*lst, del);
Then we change the lst pointer to next_node again
so it become the first again and can enter the while loop again.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = NULL;
}
