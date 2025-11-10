/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:48:15 by levincen          #+#    #+#             */
/*   Updated: 2024/11/23 13:26:47 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_print_str(char *str);
int		ft_print_percent(void);
int		ft_print_udecimal(unsigned int n);
int		ft_putnbr(long int n);
int		ft_print_hexa(unsigned long nb, char *format);
int		ft_printptr(unsigned long int nb);

#endif
