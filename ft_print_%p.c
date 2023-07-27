/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_%p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:50:03 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 17:06:41 by bapereir         ###   ########.fr       */
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
