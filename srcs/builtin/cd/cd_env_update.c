/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:53:57 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:56:59 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	update_dup_env_var(t_ms *ms, char *key, char *value)
{
	int		i;
	char	*new_entry;
	char	*key_eq;

	key_eq = ft_strjoin(key, "=");
	if (!key_eq)
		return ;
	new_entry = ft_strjoin(key_eq, value);
	free(key_eq);
	if (!new_entry)
		return ;
	i = 0;
	while (ms->dup_env && ms->dup_env[i])
	{
		if (ft_strncmp(ms->dup_env[i], key, ft_strlen(key)) == 0
			&& ms->dup_env[i][ft_strlen(key)] == '=')
		{
			free(ms->dup_env[i]);
			ms->dup_env[i] = new_entry;
			return ;
		}
		i++;
	}
	add_to_dup_env(ms, new_entry);
	free(new_entry);
}
