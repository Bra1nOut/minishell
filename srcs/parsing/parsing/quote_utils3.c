/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:04:31 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/07 15:25:14 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	init_expander_data(t_env_exp *exp, const char *str)
{
	exp->result_size = ft_strlen(str) * 1000;
	exp->result = malloc(exp->result_size);
	exp->env_var = malloc(300);
	exp->result_pos = 0;
}
