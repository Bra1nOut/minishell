/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:53:25 by jockova           #+#    #+#             */
/*   Updated: 2025/06/18 14:51:25 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ms_print_envlst(t_ms ms)
{
	t_envlst *cur = ms.env_lst;
	int i;

	i = 1;
	if (!cur)
	{
		printf("no env list\n");
		return;
	}
	printf("environment list variables:\n");
	while (cur)
	{
		printf("%d: %s=%s\n", i++, cur->key, cur->value);
		if (!cur->next)
			printf("Reached end of env_lst at index %d\n", i - 1);
		cur = cur->next;
	}
}

void ms_print_state(t_ms *ms)
{
	if (!ms)
	{
		printf("t_ms pointer is NULL\n");
		return;
	}

	printf("t_ms state:\n");
	printf("  env_lst: %p\n", (void *)ms->env_lst);
	printf("  token:   %p\n", (void *)ms->token);
	printf("  cmd:     %p\n", (void *)ms->cmd);
}