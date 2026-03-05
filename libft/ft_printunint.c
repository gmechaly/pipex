/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:15:21 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:57 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_printunint(unsigned int nbr)
{
	int					j;
	char				u;
	static unsigned int	i;

	j = i;
	u = '0' + nbr % 10;
	nbr = nbr / 10;
	if (nbr != 0)
		ft_printunint(nbr);
	write (1, &u, 1);
	i++;
	return (i - j);
}
