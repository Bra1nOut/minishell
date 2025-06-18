/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:54:17 by jockova           #+#    #+#             */
/*   Updated: 2025/03/17 14:32:27 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates a new node for a linked list.
It takes one parameter:
	~content, that will be stored in the node's content member variable. 
Allocates memory for the new node using malloc
Initializes the content member variable with the value of the content parameter.
The next member variable is initialized to NULL.
Yannik node = (t_list *)malloc(sizeof(t_list));
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
