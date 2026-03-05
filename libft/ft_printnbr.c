/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:14:51 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:43 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_printnbr(int nbr)
{
	int			j;
	char		u;
	static int	i;

	j = i;
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		u = '-';
		i++;
		write (1, &u, 1);
	}
	u = '0' + nbr % 10;
	nbr = nbr / 10;
	if (nbr != 0)
		ft_printnbr(nbr);
	write (1, &u, 1);
	i++;
	return (i - j);
}
