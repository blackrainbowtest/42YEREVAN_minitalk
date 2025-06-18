/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:18:56 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/18 19:36:24 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_ack = 0;

// void	send_char(pid_t pid, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		if ((c >> i) & 1)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(300);
// 		i++;
// 	}
// }

/**
 * @file client.c
 * 
 * @brief	Client-side code for sending characters to a server process via signals.
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
		ft_send_bit(server_pid, (c >> 1) & 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\n');
	return (0);
}
