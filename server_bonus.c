/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:51:45 by root              #+#    #+#             */
/*   Updated: 2025/06/21 19:58:32 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * @file server.c
 * @brief Signal handler for receiving bits from the client.
 *
 * Builds characters from 8 bits sent by the client using signals.
 * Sends SIGUSR1 as ACK for each bit.
 * Sends SIGUSR2 when a full message (`\0`) is received.
 *
 * @param sig The received signal (SIGUSR1 or SIGUSR2).
 * @param info Signal metadata containing the client PID.
 * @param context Unused context pointer.
 */
void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		character |= (1 << bit_count);
	++bit_count;
	if (bit_count == 8)
	{
		if (character == '\0')
		{
			bit_count = 0;
			character = 0;
			kill(client_pid, SIGUSR2);
			return ;
		}
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
	kill(client_pid, SIGUSR1);
}

/**
 * @file server.c
 * @brief Entry point for the server program.
 *
 * Displays its PID and waits for incoming signals from 
 * clients to reconstruct and print messages.
 *
 * @return int Exit status code.
 */
int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
