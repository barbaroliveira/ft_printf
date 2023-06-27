/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:09:26 by bapereir          #+#    #+#             */
/*   Updated: 2023/06/06 16:09:33 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
/*__________________________________[libraries]_________________________________*/


/*_________________________________[FUNCTIONS]________________________________*/
int ft_putchar(char c);
int ft_printstr(char *str);
int ft_formats(va_list args, const char format);
int ft_printf(const char *str, ...);

#endif