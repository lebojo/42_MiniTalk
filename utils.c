/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:13:23 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/17 19:11:16 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

unsigned int	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;
	unsigned int	s;

	i = 0;
	s = 0;
	while (src[s])
		s++;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}

int	ft_putstr(int nb, char *str, ...)
{
	int		i;
	char	*tmp;
	va_list	l;

	i = 0;
	va_start(l, str);
	while (str[i])
		write(1, &str[i++], 1);
	while (--nb)
	{
		i = 0;
		tmp = va_arg(l, char *);
		if (tmp == NULL)
			break ;
		while (tmp[i])
			write(1, &tmp[i++], 1);
	}
	va_end(l);
	return (i);
}

int	intlen(int s)
{
	int	i;

	i = 0;
	if (s < 0)
	{
		s *= -1;
		i++;
	}
	while (s > 9)
	{
		s /= 10;
		i++;
	}
	return (i);
}

char	*itoa(int val)
{
	char	*num;
	char	*str;
	int		i;
	int		ii;

	str = malloc(sizeof(char) * intlen(val) + 2);
	num = "0123456789abcdef";
	ii = intlen(val) + 1;
	str[ii] = '\0';
	if (val < 0)
	{
		*str++ = '-';
		val = -val;
	}
	i = val;
	while (i)
	{
		str[--ii] = num[i % 10];
		i /= 10;
	}
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
