/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:47:59 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:06:38 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

#define MAX "9223372036854775807"
#define MIN "-9223372036854775808"

void	ft_exit_num_arg_error(t_cmd *cmd)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(cmd->cmd_param[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static int	is_numeric(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_ms *ms, t_cmd *cmd)
{
	long long	status;

	status = 0;
	ft_putstr_fd("exit\n", 1);
	if (cmd && cmd->cmd_param && cmd->cmd_param[1])
	{
		if (!is_numeric(cmd->cmd_param[1])
			|| !ft_atoll(cmd->cmd_param[1], &status, 0))
		{
			ft_exit_num_arg_error(cmd);
			free_all(ms);
			free(ms);
			exit(2);
		}
		if (cmd->cmd_param[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			ms->status = 1;
			return ;
		}
	}
	ms->status = (unsigned char)status;
	free_all(ms);
	rl_clear_history();
	exit(ms->status);
}
