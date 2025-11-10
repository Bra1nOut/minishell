/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:47:41 by levincen          #+#    #+#             */
/*   Updated: 2024/11/06 18:14:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*o;

	i = 0;
	o = (void *)s;
	while (i < n)
	{
		if (o[i] == (char) c)
			return (&o[i]);
		i++;
	}
	return (NULL);
}
