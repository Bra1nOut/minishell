/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:42:11 by jockova           #+#    #+#             */
/*   Updated: 2025/03/17 14:33:25 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns the last node of a linked list data structure.
The function takes one parameter, 
	~lst, which is a pointer to the first node of the list.
The function uses a loop to iterate through the list,
following the next pointers of each node,
until it reaches the end of the list, and returns the last node.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
