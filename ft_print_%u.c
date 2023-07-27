/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_%u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:04:27 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 17:06:45 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	if (nb < 10)
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
