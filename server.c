/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:08:39 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/12 21:49:30 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"
#include <stdio.h>

void	str_constructor(char c)
{
	static char	*res = NULL;
	static int	index = 0;
	char		*tmp;
	int			i;
	
	i = 0;
	tmp = malloc(index);
	while (res != NULL && res[i])
	{
		tmp[i] = res[i];
		i++;
	}
	if (res != NULL) //== C'est pas le début d'un message
		free(res);
	res = malloc(index + 1);
	i = 0;
	while (tmp[i])
	{
		res[i] = tmp[i];
		i++;
	}
	free(tmp);
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

void	char_constructor(int bit)
{
	static char c = '0';
	static int	i = 0;
	
	c = (c << 1) | bit;
	i++;
	if (i == 8)
	{
		str_constructor(c);
		i = 0;
	}
}

void	one()
{
	char_constructor(1);
}

void	zero()
{
	char_constructor(0);
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
		signal(SIGUSR1, &one);
		signal(SIGUSR2, &zero);
	}
}
