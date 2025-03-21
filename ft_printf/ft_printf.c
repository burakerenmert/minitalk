/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:14:41 by buramert          #+#    #+#             */
/*   Updated: 2024/10/30 00:34:51 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parser(char a, va_list args)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (a == 'c')
		count = ft_putchar (va_arg(args, int));
	else if (a == 's')
		count = ft_putstr (va_arg(args, char *));
	else if (a == 'd' || a == 'i')
		count = ft_putnbr (va_arg(args, int));
	else if (a == 'u')
		count = ft_putunsigned (va_arg(args, unsigned int));
	else if (a == 'x')
		count = ft_puthex(va_arg(args, unsigned int), hex);
	else if (a == 'X')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (a == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_puthex(va_arg(args, unsigned long long), hex);
	}
	else if (a == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parser (str[++i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
