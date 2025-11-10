/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:50:20 by levincen          #+#    #+#             */
/*   Updated: 2025/10/02 18:18:18 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char s1[] = "ABCD";
	char s2[] = "ABC";

	printf("%d\n", strcmp(s1, s2));
	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
*/
