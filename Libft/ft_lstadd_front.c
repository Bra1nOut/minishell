/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:17:13 by jockova           #+#    #+#             */
/*   Updated: 2025/03/14 15:24:07 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Takes in two parameters: 
  		~a pointer to a pointer of the first link/node of a list (lst), 
  		~a pointer to the new node to be added to the list (new). 
 Adds the node "new" to the beginning of the list, 
 and does not return any value. 
 No external functions are used.
 
 IMPLEMENTATION
 1)Checks if both the "lst" and "new" pointers are not NULL.
 2)If they are not,
 		 it sets the next pointer of the "new" node 
 		 to the current first node of the list (pointed to by "lst").
 3)Then it updates the "lst" pointer to point to the "new" node, 
 making it the new first node of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
