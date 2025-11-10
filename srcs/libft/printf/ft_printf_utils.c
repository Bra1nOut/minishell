/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:28:51 by levincen          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:57 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putnbr(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_print_udecimal(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_print_udecimal(n / 10);
		ft_print_udecimal(n % 10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
	count++;
	return (count);
}

// int	main()
// {
// 	printf("%p\n",);

// 	return 0;
// }
