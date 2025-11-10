/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:33:02 by levincen          #+#    #+#             */
/*   Updated: 2025/10/30 17:26:27 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*find_env_value(char *env_line)
{
	int	i;

	i = 0;
	while (env_line[i] && env_line[i] != '=')
		i++;
	if (env_line[i] == '\0')
		return (NULL);
	return (ft_substr(env_line, i + 1, ft_strlen(env_line) - (i + 1)));
}

char	*find_env_key(char *env_line)
{
	int	i;

	i = 0;
	while (env_line[i] && env_line[i] != '=')
		i++;
	return (ft_substr(env_line, 0, i));
}

void	ft_add_env_to_end(t_env **head, t_env *new)
{
	t_env	*tmp;

	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
