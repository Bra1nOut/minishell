/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:48:37 by jockova           #+#    #+#             */
/*   Updated: 2024/12/13 10:22:11 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*string;
	size_t	i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char string1[] = "000000";
	char string2[] = "000000";
	char character = '1';
	ft_memset(string1, '1', 3);
	printf("%s\n", string1);
	ft_memset(string2, character, 3);
	printf("%s\n", string2);
	return (0);
}
*/