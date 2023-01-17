/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:14:59 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/17 18:26:56 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>

int				ft_putstr(int nb, char *str, ...);
char			*itoa(int val);
int				ft_atoi(const char *str);
unsigned int	ft_strcpy(char *dst, const char *src);

#endif