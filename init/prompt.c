/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:21:11 by jockova           #+#    #+#             */
/*   Updated: 2025/06/18 13:03:42 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "minishell.h"
	
	void	handle_sigint_ctrlC(int sig)
	{
		if (sig == SIGINT)
		{
			g_sig = 1; // sets to 1: signal was received
			write(1, "\n", 1);
			rl_on_new_line(); // informs Readline that the cursor is on a new line, so it can redraw the prompt
			rl_replace_line("", 0); // clears the current input line, whatever the user typed before
			rl_display(); // redraws the prompt line
		}
	}
	
	void	prompt(t_ms *minishell)
	{
		char	*line;
		
		while (1)
		{
			g_sig = 0;
			signal(SIGINT, handle_sigint_ctrlC) // Ctrl-C cuts running process, gives new line/prompt
			signal(SIGQUIT, SIG_IGN); // Ctrl-\ quits program, SIG_IGN ignores when in prompt waiting
			line = readline("minishell> "); // 
			// if (!line)
			// 	free_all(&data, "exit\n", data.exit_code);
			printf("You typed: [%s]\n", line);
			printf("You typed: >>%s<<\n", line);
			// if (empty_line(line))
			// 	continue ;
			
			add_history(line); // stored in RAM and lost when shell exits
			// if (!parseline(&data, line))
			// 	continue ;
			free(line);
		}
	}
	