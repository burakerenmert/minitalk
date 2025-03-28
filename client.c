/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakerenmert <burakerenmert@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:29:42 by buramert          #+#    #+#             */
/*   Updated: 2025/03/21 05:51:13 by burakerenme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal_check = 0;

void	signal_handler(int signal_number)
{
	if (signal_number == SIGUSR1)
		g_signal_check = 1;
	else
		exit(EXIT_FAILURE);
}

void	bit_converter(int server_pid, char *str)
{
	int	i;
	int	bit;

	i = -1;
	while (str[++i])
	{
		bit = 7;
		while (--bit >= 0)
		{
			g_signal_check = 0;
			if ((str[i] >> bit) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (g_signal_check == 0)
				pause();
		}
	}
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*str;
	int		len_pid;

	if (ac == 3)
	{
		len_pid = ft_strlen(av[1]);
		server_pid = ft_atoi(av[1]);
		if (kill(server_pid, 0) == -1 || server_pid > 4194304
			|| server_pid < 0 || len_pid > 7)
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
		str = av[2];
		signal(SIGUSR1, signal_handler);
		bit_converter(server_pid, str);
		bit_converter(server_pid, "\n");
	}
	else
		ft_printf("Error: %s - Usage: <program> <PID> <message>\n", av[0]);
	return (0);
}
