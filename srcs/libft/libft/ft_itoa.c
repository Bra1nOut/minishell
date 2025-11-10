/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:45:52 by levincen          #+#    #+#             */
/*   Updated: 2024/11/11 14:15:16 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	result[size] = '\0';
	while (n > 0)
	{
		size--;
		result[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
