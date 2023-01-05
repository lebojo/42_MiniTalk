/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:14:59 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/05 18:26:07 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>

int		ft_putstr(int nb, char *str, ...);
char	*itoa(int val, int base);
int		ft_atoi(const char *str);

#endif