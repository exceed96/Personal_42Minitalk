/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:40:23 by sangyeki          #+#    #+#             */
/*   Updated: 2022/05/08 14:26:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	get_write(int signum, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static pid_t			c_pid = 0;

	(void)context;
	if (!c_pid)
		c_pid = info->si_pid;
	c |= (SIGUSR2 == signum);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		if (c == 127)
		{
			kill(c_pid, SIGUSR2);
			c_pid = 0;
			ft_putchar_fd('\n', 1);
			c = 0;
			return ;
		}
		c = 0;
		kill(c_pid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_write;
	sig.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID Number : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
