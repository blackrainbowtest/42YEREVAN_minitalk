/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:51:45 by root              #+#    #+#             */
/*   Updated: 2025/06/16 19:59:38 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @file server.c
 * 
 * @brief override default user signals
 * @param sig signal integer
 * @returns void
 */
void	handle_signal(int sig)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	if (sig == SIGUSR2)
		character |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
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
	len = 0;
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
