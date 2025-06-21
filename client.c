/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:18:56 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/21 10:19:02 by root             ###   ########.fr       */
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
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		g_ack = 2;
}

static int	ft_wait_for_ack(int expected)
{
	int	timeout;

	timeout = 0;
	while (g_ack != expected)
	{
		usleep(100);
		if (++timeout > 100)
			return (0);
	}
	return (1);
}

/**
 * @file client.c
 * 1000000 microsecond = 1 second
 */
void	ft_send_bit(pid_t server_pid, int bit)
{
	int	retryes;

	retryes = 0;
	while (1)
	{
		g_ack = 0;
		if (bit)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		if (ft_wait_for_ack(1))
			break ;
		if (++retryes >= 5)
		{
			ft_putstr_fd("Error: Server not respond.\n", 2);
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
		ft_putstr_fd("Usage: ./client <PID> <message>\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_ack_handle);
	msg = argv[2];
	i = 0;
	while (msg[i])
		ft_send_char(server_pid, msg[i++]);
	ft_send_char(server_pid, '\0');
	if (!ft_wait_for_ack(2))
	{
		ft_putstr_fd("Error: Final ACK not received.\n", 2);
		exit(1);
	}
	return (0);
}
