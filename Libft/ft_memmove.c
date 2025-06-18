/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:48:52 by jockova           #+#    #+#             */
/*   Updated: 2024/12/12 14:52:02 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char const	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (d < s || d >= s + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
int	main(void)
{
    char src1[12] = "Hello World";
	char src2[12] = "Hello World";

	ft_memmove(src1 + 2, src1, 5);
	ft_memmove(src2 + 2, src2, 5);
	printf("Source1: %s\n", src1);
	printf("Source2: %s\n", src2);
	return (0);
}
*/