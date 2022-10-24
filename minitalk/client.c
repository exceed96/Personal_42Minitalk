/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:40:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/05/08 14:26:46 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	received_write(int sig)
{
	static int	received_count = 0;

	if (sig == SIGUSR1)
		received_count++;
	else
	{
		ft_putnbr_fd(received_count, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	ft_kill(int pid_number, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid_number, SIGUSR2);
			else
				kill(pid_number, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		if (i == 7)
			kill(pid_number, SIGUSR1);
		else
			kill(pid_number, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Wrong count of argument\n", 1);
		return (0);
	}
	ft_putstr_fd("Client Sent : ", 1);
	ft_putstr_fd(argv[2], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received Server : ", 1);
	signal(SIGUSR1, received_write);
	signal(SIGUSR2, received_write);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
