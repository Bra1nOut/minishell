/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:31:38 by jockova           #+#    #+#             */
/*   Updated: 2024/11/22 11:31:39 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(unsigned char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char letter1 = 'a';
	char letter2 = 5;
	printf("%d\n", ft_isalpha(letter1));
	printf("%d\n", isalpha(letter1));
	printf("%d\n", ft_isalpha(letter2));
	printf("%d\n", isalpha(letter2));
	printf("%d\n", ft_isalpha(':'));
	printf("%d\n", isalpha(':'));
	return (0);
}
*/