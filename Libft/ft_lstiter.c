/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:32:10 by jockova           #+#    #+#             */
/*   Updated: 2025/03/17 14:30:22 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Takes in 
 	~a pointer to a t_list 
	~a pointer to a function that takes in a void pointer

It iterates through the list, starting with the first node,
and applies the function to the content of each node 
by dereferencing the content pointer 
and passing it as a parameter to the function.

It then moves on to the next node 
in the list until it reaches the end.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
