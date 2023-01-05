/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:13:23 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/05 18:26:05 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

int	ft_putstr(int nb, char *str, ...)
{
	int	i;
	char *tmp;
	va_list l;

	i = 0;

	va_start(l, str);
	while (str[i])
		write(1, &str[i++], 1);
	while (--nb)
	{
		i = 0;
		tmp = va_arg(l, char*);
		if (tmp == NULL)
			break ;
		while (tmp[i])
			write(1, &tmp[i++], 1);
	}
	va_end(l);
	return (i);
}

char	*rev(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	res = malloc(sizeof(char) * len + 1);
	while (len-- >= 0)
			res[i++] = str[len];
	res[--i] = '\0';
	free(str);
	return(res);
}

char	*itoa(int val, int base)
{
	char	*num;
	char	*str;
	int		i;
	int		ii;

	str = malloc(sizeof(char) * 32);
	num = "0123456789abcdef";
	ii = 0;
	if (val < 0)
	{
		*str++ = '-';
		val = -val;
	}
	i = val;
	while (i)
	{
		str[ii++] = num[i % base];
		i /= base;
	}
	str = rev(str);
	return (str);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			res_sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res_sign * res);
}
