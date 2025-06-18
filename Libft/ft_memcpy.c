/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:15:16 by jockova           #+#    #+#             */
/*   Updated: 2024/12/12 10:25:24 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
    char src[10] = "Hello";
    char dest[10] = "ABCDEFGH";

    ft_memcpy(dest, src, 5); // Overwrite the first 5 bytes of dest with src
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
	return (0);
}
*/