/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:32:16 by levincen          #+#    #+#             */
/*   Updated: 2025/10/10 18:50:10 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
