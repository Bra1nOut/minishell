/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:18:30 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:15:06 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*complete_path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (ft_strdup(cmd));
		complete_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!complete_path)
			return (ft_strdup(cmd));
		if (access(complete_path, F_OK | X_OK) == 0)
			return (complete_path);
		free(complete_path);
		i++;
	}
	return (ft_strdup(cmd));
}

char	*ft_find_path(char *cmd, t_env *env)
{
	char	*path_env;
	char	**paths;
	char	*heureka;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_env(env, "PATH");
	paths = ft_split(path_env, ":");
	if (!path_env || !paths)
		return (NULL);
	heureka = check_path(paths, cmd);
	free_array(paths);
	return (heureka);
}
