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

#include "printf.h"

/*criar regra para %c - return 1 char*/
//ft_putchar
int ft_putchar(char c)
{
	write(1, &c, 1);
}

/*criar regra para %s - return uma string
   - logica do putchar com um ciclo para aceitar uma string*/
int ft_printstr(char *str)
{
    int i;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

//criar uma regra geral que define a funcao que vai utilizar
//dependendo dos argumentos passados no printf
int ft_formats(va_list args, const char format)
{
    int print_length;
    print_length = 0;
    if(format == 'c')
        print_length = ft_putchar(va_arg(args, int));
    else if(format == 's')
        print_length = 0;
        print_length = ft_printstr(va_arg(args, int));
    else if(format == 'p')
        print_length = 0;
        //definir funcao a ser utilizada para p
    else if(format == 'd'|| format == 'i')
        print_length = 0;
        //definir funcao a ser utilizada para d e i
    else if(format == 'u')
        print_length = 0;
        //definir funcao a ser utilizada para u
    else if(format == 'x' || format== 'X')
        print_length = 0;
        //definir funcao a ser utilizada para x e X
    else if(format == '%')
        print_length = 0;
        //definir funcao a ser utilizada para %
    return(print_length);
}

/*criar regra para %d - return de um pointer em formato decimal*/
/*criar regra para %i - return de um integer na base 10*/
//ft_putnbr

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
