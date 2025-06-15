/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:51:45 by root              #+#    #+#             */
/*   Updated: 2025/06/15 23:08:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	if (sig == SIGUSR2)
		character |= (1 << bit_count);
	bit_count++;
	printf("bit count %d", bit_count);
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	char	buffer[32];
	int		len;

	pid = getpid();
	len = 0;
	while (pid > 0)
	{
		buffer[len++] = (pid % 10) + '0';
		pid /= 10;
	}
	write(1, "PID: ", 5);
	while (len--)
		write(1, &buffer[len], 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}
