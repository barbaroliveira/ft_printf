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

/*functions of pointer*/
//funtion who counts the number of adress's
/*criar regra para %p - return de um pointer em formato hexadecimal*/
//putnbr_base??
int	ft_address_len(unsigned long long n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ft_put_adress(unsigned long long n)
{
	char	result;

	if (n >= 16)
	{
		ft_put_adress(n / 16);
		ft_put_adress(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			result = n + '0';
			ft_putchar(result);
		}
		else
		{
			result = n - 10 + 'a';
			ft_putchar(result);
		}
	}
}

int	ft_print_address(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_printstr("(nil)");
	}
	else
	{
		ft_putstr("0x");
		len += 2;
		ft_put_adress(n);
		len += ft_address_len(n);
	}
	return (len);
}

/*functions to %d and %i*/
//print_nbr is a funtion that deals with every int value
//and returns the lenght of that value
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

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	ft_putnbr(n);
	return (ft_nbrlen(n));
}

/*criar regra para %% - return de um sinal de %*/
int	ft_print_percent(void)
{
	ft_putchar('%');
	return (1);
}

/*criar regra para %u - return de um unsigned decimal na base 10*/
int	ft_putchar_int(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

void	ft_print_unsig(unsigned int nb, int *count)
{
	if(nb < 10)
	{
		*count += ft_putchar_int(nb + 48);
		return ;
	}
	else
		ft_print_unsig(nb / 10, count);
	ft_print_unsig(nb % 10, count);
}

int	ft_put_unsigned(unsigned int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_print_unsig(n, &count);
	return (count);
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
			if(format == 'x')
				ft_putchar(n - 10 + 'a');
			else if(format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int ft_print_hex(unsigned int n, const char format)
{
	int len;

	len = 0;
	if(n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if(format == 'x')
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
	else if(str[*i] == 'p')
		letter_count += ft_print_address(va_arg(arg, unsigned long long));
	else if(str[*i] == 'd' || str[*i] == 'i')
		letter_count += ft_print_nbr(va_arg(arg, int));
	else if(str[*i] == '%')
		letter_count += ft_print_percent();
	else if(str[*i] == 'x' || str[*i] == 'X')
		letter_count += ft_print_nbr(va_arg(arg, unsigned int));
	else if(str[*i] == 'u')
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
