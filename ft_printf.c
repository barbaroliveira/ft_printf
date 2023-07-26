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
	if(!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	i += ft_strlen(str);
	return (i);
}
/*functions of pointer*/
//funtion who counts the number of adress's
int	ft_address_len(unsigned long long n)
{
	int	count;

	count = 0;
	while(n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ft_put_adress(int long long n)
{
	if (n >= 16)
	{
		ft_put_adress(n / 16);
		ft_put_adress(n % 16);
	}
	else
	{
		if(n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_address(unsigned long long n)
{
	int	len;

	len = 0;
	if(n == 0)
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

int ft_nbrlen(int n)
{
	int i = 0;
	if(n <= 0)
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

int	ft_formats(va_list arg, const char *str, size_t *i)
{
	int	letter_count;

	letter_count = 0;
	if (str[*i] == 'c')
		letter_count += ft_putchar(va_arg(arg, int));
	else if (str[*i] == 's')
		letter_count += ft_printstr(va_arg(arg, char *));
	else if(str[*i] == 'p')
		letter_count += ft_print_address(va_arg(arg, unsigned long long));
	else if(str[*i] == 'd' || str[*i] == 'i')
		letter_count += ft_print_nbr(va_arg(arg, int));
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
