/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:09:08 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/05 01:20:05 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putstr("Pas d'arguments\n"));
	ft_putstr(argv[1]);
	ft_putstr(" danse sur un chat dans les etoiles de Norbert la grande lune\n");
}
