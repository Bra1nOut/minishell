/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:00 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:20:21 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp("echo", cmd) == 0 || ft_strcmp("cd", cmd) == 0
		|| ft_strcmp("pwd", cmd) == 0 || ft_strcmp("export", cmd) == 0
		|| ft_strcmp("unset", cmd) == 0 || ft_strcmp("env", cmd) == 0
		|| ft_strcmp("exit", cmd) == 0)
	{
		return (1);
	}
	return (0);
}
