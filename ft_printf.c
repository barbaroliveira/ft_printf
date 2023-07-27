/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:08:57 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 17:05:17 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*criar regra para %% - return de um sinal de %*/
int	ft_print_percent(void)
{
	ft_putchar('%');
	return (1);
}

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

int	ft_print_hex(unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (format == 'x')
		len += ft_printstr("0x");
	else if (format == 'X')
		len += ft_printstr("0X");
	ft_put_hex(n, format);
	return (len);
}

int	ft_formats(va_list arg, const char *str, size_t *i)
{
	int	letter_count;

	letter_count = 0;
	if (str[*i] == 'c')
		letter_count += ft_print_chr(va_arg(arg, int));
	else if (str[*i] == 's')
		letter_count += ft_printstr(va_arg(arg, char *));
	else if (str[*i] == 'p')
		letter_count += ft_print_address(va_arg(arg, unsigned long long));
	else if (str[*i] == 'd' || str[*i] == 'i')
		letter_count += ft_print_nbr(va_arg(arg, int));
	else if (str[*i] == '%')
		letter_count += ft_print_percent();
	else if (str[*i] == 'x' || str[*i] == 'X')
		letter_count += ft_print_nbr(va_arg(arg, unsigned int));
	else if (str[*i] == 'u')
		letter_count += ft_put_unsigned(va_arg(arg, unsigned int));
	return (letter_count);
}

/*criar funcao principal que vai chamar as funcoes !=s
*/
int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			count;
	size_t		i;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_formats(arg, format, &i);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
