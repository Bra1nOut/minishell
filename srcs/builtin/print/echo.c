/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:04:34 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 10:06:41 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_echo(t_cmd *cmd, t_ms *ms)
{
	int		i;
	bool	option;

	i = 1;
	option = false;
	if (cmd->cmd_param[1] && !ft_strcmp(cmd->cmd_param[1], "-n"))
	{
		i = 2;
		option = true;
	}
	while (cmd->cmd_param[i])
	{
		printf("%s", cmd->cmd_param[i]);
		if (cmd->cmd_param[i + 1])
			printf(" ");
		i++;
	}
	if (option == false)
		printf("\n");
	ms->status = 0;
	return (1);
}
