/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_%x%X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:33:59 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 18:35:49 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*criar regra para %x - return de um numero em hexadecimal formato lowercase*/
/*criar regra para %X - return de um numero em hexadecimal formato uppercase*/
//chamar putnbr_base e fazer if para transformar em lower e upper
void	ft_put_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_put_hex(n, format);
	return (hex_len(n));
}
