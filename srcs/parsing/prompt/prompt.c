/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:35:21 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 11:31:54 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*ft_make_prompt(void)
{
	char	cwd[4096];
	char	*dir;
	char	*prompt;
	char	*tmp;

	if (!getcwd(cwd, sizeof(cwd)))
		return (ft_strdup("minishell> "));
	dir = ft_strrchr(cwd, '/');
	if (!dir)
		dir = cwd;
	else
		dir++;
	tmp = ft_strjoin(BOLD_GREEN "minishell:" BOLD_BLUE, dir);
	if (!tmp)
		return (NULL);
	prompt = ft_strjoin(tmp, BOLD_RED "> " RESET);
	free(tmp);
	return (prompt);
}

static int	process_input_line(t_ms *ms, char *line)
{
	if (handle_empty_line(line))
		return (free(line), 1);
	if (handle_validation_quote(line))
		return (free(line), 1);
	if (handle_syntax_check(ms, line))
		return (free(line), 1);
	create_and_exec_cmd(ms);
	if (ms->token)
	{
		free_token(ms->token);
		ms->token = NULL;
	}
	if (ms->cmd)
		free_cmd(&ms->cmd);
	free(line);
	if (g_signal != 0)
	{
		ms->status = g_signal;
		g_signal = 0;
	}
	return (0);
}

void	ft_prompt(t_ms *ms)
{
	char	*line;

	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		line = get_user_input();
		if (!line)
			break ;
		if (g_signal != 0)
		{
			ms->status = g_signal;
			g_signal = 0;
		}
		if (process_input_line(ms, line))
			continue ;
	}
	free_all(ms);
	free(ms);
}
