/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:18:56 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/21 19:58:27 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * @file client.c
 * @brief Signal handler to acknowledge receipt of a signal from the server.
 *
 * @param sig The signal received (SIGUSR1 for bit ACK, SIGUSR2 for message end).
 */
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

/**
 * @file client.c
 * @brief Waits for a specific ACK value from the server.
 *
 * @param expected The expected value of g_ack (1 for bit ACK, 2 for final ACK).
 * @return int 1 if the expected ACK is received, 0 if timeout occurs.
 */
static int	ft_wait_for_ack(int expected)
{
	int	timeout;

	timeout = 0;
	while (g_ack != expected)
	{
		usleep(100);
		if (++timeout > 200)
			return (0);
	}
	return (1);
}

/**
 * @file client.c
 * @brief Sends a single bit to the server and waits for confirmation.
 *
 * Retries up to 5 times if no confirmation is received.
 *
 * @param server_pid The PID of the server.
 * @param bit The bit to send (0 or 1).
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
		if (ft_wait_for_ack(1) || g_ack == 2)
			break ;
		if (++retryes >= 5)
		{
			ft_putstr_fd("ERROR: Server not respond.\n", 1);
			exit(1);
		}
	}
}

/**
 * @file client.c
 * @brief Sends a character to the server bit by bit.
 *
 * @param server_pid The PID of the server.
 * @param c The character to send.
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

/**
 * @file client.c
 * @brief Entry point for the client program.
 *
 * Sends a string to the server process specified by PID using Unix signals.
 *
 * @param argc Number of arguments.
 * @param argv Argument array: argv[1] is the PID, argv[2] is the message.
 * @return int Exit status code.
 */
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*msg;
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("ERROR: ./client <PID> <message>\n", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_ack_handle);
	signal(SIGUSR2, ft_ack_handle);
	msg = argv[2];
	i = 0;
	while (msg[i])
		ft_send_char(server_pid, msg[i++]);
	ft_send_char(server_pid, '\0');
	if (!ft_wait_for_ack(2))
	{
		ft_putstr_fd("ERROR: Final ACK not received.\n", 1);
		exit(1);
	}
	return (0);
}
