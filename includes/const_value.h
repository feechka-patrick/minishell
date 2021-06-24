/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_value.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:31:34 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 20:08:06 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VALUE_H
# define CONST_VALUE_H

# define BUFER_SIZE 1000
# define BASH_NAME "\033[1;32mnmi\033[1;31ms\033[2;32mtune\033[0m $ "
# define BASH "nmistune: "

# define QUOTE 34
# define APOSTROPHE 39
# define BACKSLASH 92
# define DOLLAR 36
# define SEMICOLON 59
# define SPACE 32
# define PIPE 124
# define REDIRECT ">\0"
# define REV_REDIRECT "<"
# define DOUBLE_REDIRECT ">>"
# define REV_DOUBLE_REDIRECT "<<"

# define UP "\e[A"
# define DOWN "\e[B"
# define BKSP "\x7f"
# define LEFT "\e[D"
# define RIGHT "\e[C"
# define CTRLD "\4"

# define FLAG_NONE	0b00000000
# define FLAG_C	    0b00000001
# define FLAG_ERROR	0b00000010
# define FLAG_EXIT	0b00000100

#endif