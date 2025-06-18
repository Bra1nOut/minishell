/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:26:46 by jockova           #+#    #+#             */
/*   Updated: 2024/12/13 10:35:47 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char string1[] = "111111";
	char string2[] = "111111";
	ft_bzero(string1, 3);
	bzero(string2, 3);
	printf("%s\n", &string1[4]);
	printf("%s\n", &string2);
	return (0);
}
*/