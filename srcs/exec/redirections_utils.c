/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:45:45 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 16:48:12 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirection_assign_fd(t_cmd *cmd, int type, int fd)
{
	if (type == IN || type == HEREDOC)
		cmd->infile = fd;
	if (type == OUT || type == APPEND)
		cmd->outfile = fd;
}

int	redirection_file_error(t_ms *ms, char *filename)
{
	perror(filename);
	ms->status = 1;
	return (-1);
}
