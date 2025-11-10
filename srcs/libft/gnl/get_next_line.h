/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:11 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 17:08:05 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ftt_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ftt_strjoin(char *s1, char const *s2);
char	*search_copy(char *s1);
char	*rm_start(char *buffer, const char *line);

#endif
