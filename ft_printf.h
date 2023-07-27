/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:09:26 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 11:48:37 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*_________[libraries]____________*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

/*_________[FUNCTIONS]____________*/
void	ft_put_adress(unsigned long long n);
void	ft_print_unsig(unsigned int nb, int *count);
void	ft_put_hex(unsigned int n, const char format);
void	ft_putnbr(int nb);

int		ft_print_chr(char c);
int		ft_printstr(char *str);
int		ft_address_len(unsigned long long n);
int		ft_print_address(unsigned long long n);
int		ft_nbrlen(int n);
int		ft_print_nbr(int n);
int		ft_print_percent(void);
int		ft_putchar_int(char c);
int		ft_put_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, const char format);
int		ft_formats(va_list args, const char *str, size_t *i);
int		ft_printf(const char *str, ...);

#endif
