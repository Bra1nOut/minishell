/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:47:36 by levincen          #+#    #+#             */
/*   Updated: 2024/11/22 05:04:20 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_udecimal(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), &format);
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && ++i)
			len += ft_format(args, str[i]);
		else
			len += ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}
