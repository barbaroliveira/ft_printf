/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:08:57 by bapereir          #+#    #+#             */
/*   Updated: 2023/06/06 16:09:07 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0 && nb != -2147483648)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

int	ft_formats(va_list arg, const char *str, size_t *i)
{
	int	letter_count;

	letter_count = 0;
	if (str[*i] == 'c')
		letter_count += ft_putchar(va_arg(arg, int));
	else if (str[*i] == 's')
		letter_count += ft_printstr(va_arg(arg, char *));
	return (letter_count);
}

/*criar regra para %x - return de um numero em hexadecimal formato lowercase*/
/*criar regra para %X - return de um numero em hexadecimal formato uppercase*/
//chamar putnbr_base e fazer if para transformar em lower e upper

/*criar regra para %u - return de um unsigned decimal na base 10*/
//nova?

/*criar regra para %p - return de um pointer em formato hexadecimal*/
//putnbr_base??

/*criar regra para %% - return de um sinal de %*/

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
