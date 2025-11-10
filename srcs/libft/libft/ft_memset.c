/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:50:31 by levincen          #+#    #+#             */
/*   Updated: 2024/11/06 18:09:42 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*d;

	if (s == NULL)
		return (NULL);
	d = s;
	while (len)
	{
		*d = c;
		d++;
		len--;
	}
	return (s);
}
