/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:22:21 by jockova           #+#    #+#             */
/*   Updated: 2025/06/16 14:38:27 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
colors are defined in the header, you can use the color code directly:
printf("\033[0;31mRed text\033[0m\n");
printf("\033[0;31m%zu\033[0m\n", ft_strlen(str));
or
better to keep your code clean, use #define macros in a header file 
(e.g., colors.h):
printf(RED "Error: something went wrong\n" RESET);
*/

#ifndef COLORS_H
# define COLORS_H

// for printf (C output formatting)
# define RESET "\033[0m"
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define WHITE  "\033[0;97m"

// Bold variants
# define BOLD_RESET	"\033[1m"
# define BOLD_RED   "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"

// For shell prompts (PS1-safe formatting)
# define S_RESET      "\001\033[0m\002"
# define S_RED        "\001\033[0;31m\002"
# define S_GREEN      "\001\033[0;32m\002"
# define S_YELLOW     "\001\033[0;33m\002"
# define S_BLUE       "\001\033[0;34m\002"
# define S_MAGENTA    "\001\033[0;35m\002"
# define S_CYAN       "\001\033[0;36m\002"
# define S_WHITE      "\001\033[0;37m\002"
# define S_BRIGHT_WHITE "\001\033[0;97m\002"

#endif