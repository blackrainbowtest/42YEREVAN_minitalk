/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:51:45 by root              #+#    #+#             */
/*   Updated: 2025/06/18 19:00:58 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @file server.c
 * 
 * @brief override default user signals
 * @param sig		user signal (SIGUSR1 or SIGUSR2)
 * @param info		signal info pointer
 * @param context	(old data, usually NULL)
 * @returns void
 */
void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;
	pid_t 					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		character |= (1 << bit_count);
	++bit_count;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
	kill(client_pid, SIGUSR1);
}

/**
 * @file server.c
 * 
 * @brief mian server function
 * @param void
 * @returns exit code
 */
int	main(void)
{
	struct sigaction sa;
	pid_t	pid;

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
