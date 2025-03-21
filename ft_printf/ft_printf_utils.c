/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:18:07 by buramert          #+#    #+#             */
/*   Updated: 2024/10/30 00:31:34 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	int	count;

	count = 0;
	write (1, &a, 1);
	count++;
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		count++;
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
	}
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_puthex(unsigned long long n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, hex);
	}
	count += ft_putchar(hex[n % 16]);
	return (count);
}
