/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:29:13 by buramert          #+#    #+#             */
/*   Updated: 2024/10/30 00:29:15 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_putchar(char a);
int			ft_putstr(char *str);
int			ft_printf(const char *str, ...);
int			ft_putnbr(int n);
int			ft_putunsigned(unsigned int n);
int			ft_puthex(unsigned long long n, char *hex);

#endif