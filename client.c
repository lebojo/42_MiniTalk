/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:09:08 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/17 19:00:24 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void	end_message(int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(142);
		bit--;
	}
	exit(1);
}

void	send_message(int pid, char *str)
{
	int	i;
	int	bit;

	i = -1;
	bit = 7;
	while (str[++i])
	{
		while (bit >= 0)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(142);
			bit--;
		}
		bit = 7;
	}
	end_message(pid);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (ft_putstr(1, "Not enough aarguments"));
	else if (argc > 3)
		return (ft_putstr(1, "Too many arguments"));
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
