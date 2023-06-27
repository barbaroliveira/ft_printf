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

/*criar regra para %c - return 1 char*/
//ft_putchar
int ft_putchar(char c)
{
	return (write(1, &c, 1));
    return (1);
}

/*criar regra para %s - return uma string
   - logica do putchar com um ciclo para aceitar uma string*/
int ft_printstr(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

/*criar regra para %d - return de um pointer em formato decimal*/
/*criar regra para %i - return de um integer na base 10*/
//ft_putnbr
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



//criar uma regra geral que define a funcao que vai utilizar
//dependendo dos argumentos passados no printf
int ft_formats(va_list args, const char format)
{
    int print_length;
    print_length = 0;
    if(format == 'c')
        print_length += ft_putchar(va_arg(args, int));
    else if(format == 's')
        print_length += ft_printstr(va_arg(args, int));
    else if(format == 'p')
        print_length = 0;
        //definir funcao a ser utilizada para p
    else if(format == 'd'|| format == 'i')
        print_length = ft_itoa(va_arg(args, int));
    else if(format == 'u')
        print_length = 0;
        //definir funcao a ser utilizada para u
    else if(format == 'x' || format== 'X')
        print_length = 0;
        //definir funcao a ser utilizada para x e X
    else if(format == '%')
        //definir funcao a ser utilizada para %
    return(print_length);
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
int ft_printf(const char *format, ...)
{
    va_list arg;
    int     count;

    va_start(arg, format);
    count = 0;
    while (*format != '\0')
    {
        if(*format != '%')
        {
            format++;
            count += ft_formats(*format, arg);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(arg);
    return (count);
}
