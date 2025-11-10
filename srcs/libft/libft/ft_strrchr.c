/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:15:28 by levincen          #+#    #+#             */
/*   Updated: 2024/11/14 11:20:56 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*o;

	i = 0;
	o = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			o = ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return (((char *)&s[i]));
	return (o);
}
