/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:18:56 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/18 20:06:51 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

/**
 * @file client.c
 * 
 * @brief Signal handler for acknowledging signal receipt.
 * @param sig The signal number received
 * @return void
 */
void	ft_ack_handle(int sig)
{
	(void)sig;
	g_ack = 1;
}

/**
 * @file client.c
 */
void	ft_send_bit(pid_t server_pid, int bit)
{
	int	timeout;

	timeout = 0;
	g_ack = 0;
	if (bit)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
	while (!g_ack)
	{
		usleep(100);
		++timeout;
		if (timeout > 10000)
		{
			ft_putstr_fd("Error: Server not respond.", 2);
			exit(1);
		}
	}
}

/**
 * @file client.c
 * 
 * @brief	Client-side code for sending characters to 
 * a server process via signals.
 * @param	server_pid The process ID of the server.
 * @param	c The character to be sent
 * @return	void
 */
void	ft_send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_bit(server_pid, (c >> i) & 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*msg;
	int		i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_ack_handle);
	msg = argv[2];
	i = 0;
	while (msg[i])
		ft_send_char(server_pid, msg[i++]);
	ft_send_char(server_pid, '\0');
	return (0);
}
