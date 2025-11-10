/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:04:23 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/04 18:30:15 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_token	*ft_toklast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_token	*ft_newtoklst(void)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = 1;
	new->next = NULL;
	new->value = NULL;
	new->prev = NULL;
	new->joined = false;
	return (new);
}

void	ft_tokadd_back(t_token **lst, t_token *new, char *value)
{
	t_token	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->value = value;
	last = ft_toklast(*lst);
	last->next = new;
}
