/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:25:11 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/07 16:38:50 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_sigquit(int signal)
{
	if (signal == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", 19);
		g_signal = 131;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = 130;
	}
}

void	here_doc_sigint(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		g_signal = 130;
		exit(130);
	}
}
