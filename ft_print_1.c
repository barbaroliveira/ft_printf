/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:28:28 by bapereir          #+#    #+#             */
/*   Updated: 2023/07/27 11:47:20 by bapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(char c)
{
	int	len;

	len = 0;
	ft_putchar(c);
	len += 1;
	return (len);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	i += ft_strlen(str);
	return (i);
}
