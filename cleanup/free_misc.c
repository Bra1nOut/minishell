/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:08:36 by jockova           #+#    #+#             */
/*   Updated: 2025/06/18 10:43:29 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_lst(t_envlst *head)
{
	t_envlst *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}
	// printf(RED "freed" RESET);
}
// void	free_all(t_ms *ms, char *err, int ext)
// {
// 	if (ms->cmd)
// 		free_cmd(&ms->cmd);
// 	if (ms->token)
// 		free_token(&ms->token);
// 	if (ms->env)
// 		free_list(&ms->env);
// 	if (ms->pip[0] && ms->pip[0] != -1)
// 		close(ms->pip[0]);
// 	if (ms->pip[1] && ms->pip[1] != -1)
// 		close(ms->pip[1]);
// 	if (err)
// 		print_error(err);
// 	rl_clear_history();
// 	if (!access(".heredoc.tmp", F_OK))
// 		unlink(".heredoc.tmp");
// 	if (ext != -1)
// 		exit(ext);
// }