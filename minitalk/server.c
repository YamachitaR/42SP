/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:32:23 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/05/01 09:03:47 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bit_to_char(int signal, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("The Serve PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = bit_to_char;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) < 0 || sigaction(SIGUSR2, &sa, 0) < 0)
		return (1);
	while (1)
		pause();
	return (0);
}

static void	bit_to_char(int signal, siginfo_t *info, void *context)
{
	static int	base = 1;
	static char	c = 0;
	int			pid;

	context = (void *)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		c += base;
	base *= 2;
	if (base == 256)
	{
		ft_putchar_fd(c, 1);
		base = 1;
		c = 0;
	}	
	usleep(1100);
	kill(pid, SIGUSR2);
}
