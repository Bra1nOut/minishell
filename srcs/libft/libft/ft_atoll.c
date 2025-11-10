/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:37 by levincen          #+#    #+#             */
/*   Updated: 2025/10/16 13:51:46 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LL_MAX "9223372036854775807"
#define LL_MIN "-9223372036854775808"

// LLI NAX 9 2233 72036
//          21474 83647
//          8547 75807

bool	check_overflow(long long result, int digit, int sign)
{
	if (sign == 1 && (result > (LLONG_MAX - digit) / 10))
		return (false);
	if (sign == -1 && (-result < (LLONG_MIN + digit) / 10))
		return (false);
	return (true);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

bool	ft_atoll(const char *str, long long *out, int i)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (!str || !out)
		return (false);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!ft_isdigit(str[i]))
		return (false);
	while (ft_isdigit(str[i]))
	{
		if (!check_overflow(res, str[i] - '0', sign))
			return (false);
		res = res * 10 + (str[i++] - '0');
	}
	*out = res * sign;
	return (str[i] == '\0');
}
