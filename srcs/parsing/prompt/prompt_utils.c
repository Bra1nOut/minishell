/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:17:55 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 14:55:50 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

bool	handle_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		return (true);
	return (false);
}

bool	handle_validation_quote(char *line)
{
	if (!validate_quotes(line))
	{
		ft_putstr_fd("minishell: syntax error: unclosed quotes\n",
			STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	handle_syntax_check(t_ms *ms, char *line)
{
	ms->token = ft_lst_prompt(line, ms);
	assign_token_type(ms->token);
	if (!syntax_check(ms->token) || !word_check(ms->token))
	{
		if (ms->token)
		{
			free_token(ms->token);
			ms->token = NULL;
		}
		ms->status = 2;
		return (true);
	}
	return (false);
}

void	create_and_exec_cmd(t_ms *ms)
{
	if (!pipes_checker(ms->token))
	{
		ms->cmd = create_single_cmd(ms->token);
	}
	else
		ms->cmd = create_multiple_cmd(ms->token);
	exec_cmd(ms, ms->cmd);
}

char	*get_user_input(void)
{
	char	*prompt;
	char	*line;

	prompt = ft_make_prompt();
	line = readline(prompt);
	free(prompt);
	if (!line)
	{
		printf("exit\n");
		return (NULL);
	}
	add_history(line);
	return (line);
}
