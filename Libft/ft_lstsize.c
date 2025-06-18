/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:29:10 by jockova           #+#    #+#             */
/*   Updated: 2025/03/14 15:54:49 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Counts the number of nodes in a linked list data structure.
The function takes one parameter
	~lst, which is a pointer to the first node of the list.
The function uses a loop to iterate through the list, 
following the next pointers of each node, 
each time augmenting the counter variable,
until it reaches the end of the list, 
and returns the number of nodes it has encountered (size counter).

This code allows me to move in the linked list, size
		👀 current = current->next; 👀
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
int main(void) {
    t_list *head;
    head = ft_lstnew("first node");
    head->next = ft_lstnew("second node");
    head->next->next = ft_lstnew("third node");

    printf("The number of nodes in the list is: %d\n", ft_lstsize(head));

    return 0;
}
*/