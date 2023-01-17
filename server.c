/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:08:39 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/17 19:30:53 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"
#include <stdio.h>

char	*str_init(int index, char *res)
{
	char	*tmp;

	if (index > 0)
	{
		tmp = malloc(sizeof(char) * index + 1);
		if (!tmp)
			return (NULL);
		ft_strcpy(tmp, res);
		free(res);
		res = malloc(sizeof(char) * (index + 2));
		if (!res)
		{
			free(tmp);
			return (NULL);
		}
		ft_strcpy(res, tmp);
		free(tmp);
	}
	else
		res = malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	return (res);
}

void	str_constructor(int bit)
{
	static char	*res = NULL;
	static int	index = 0;
	static char	c = '0';
	static int	i = 0;

	c = (c << 1) | bit;
	i++;
	if (i == 8)
	{
		i = 0;
		res = str_init(index, res);
		res[index++] = c;
		res[index] = '\0';
		if (c == 0)
		{
			ft_putstr(1, res);
			free(res);
			res = NULL;
			index = 0;
		}
	}
}

void	define_bit(int sig)
{
	if (sig == SIGUSR1)
		str_constructor(1);
	if (sig == SIGUSR2)
		str_constructor(0);
}

int	main(void)
{
	char	c;
	char	*pid;
	int		i;

	c = 0;
	i = 0;
	pid = itoa(getpid());
	ft_putstr(3, "PID: ", pid, "\n");
	free(pid);
	while (1)
	{
		signal(SIGUSR1, define_bit);
		signal(SIGUSR2, define_bit);
	}
}
