/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:51:49 by root              #+#    #+#             */
/*   Updated: 2025/06/15 22:42:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/**
 * signal()				- signal handler
 * SIGUSER1, SIGUSER2	- user signals 0/1
 * kill()				- send signal to other process
 */
# include <signal.h>
/**
 * pause()
 * getpid()
 */
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

// SERVER
void	handle_signal(int sig);

#endif