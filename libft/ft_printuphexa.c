/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuphexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:15:50 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/05 16:23:02 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_printuphexa(unsigned long long nbr)
{
	char			*hexabase;
	int				mod;
	int				j;
	static int		i;
	unsigned int	n;

	j = i;
	n = (unsigned int) nbr;
	hexabase = "0123456789ABCDEF";
	mod = n % 16;
	n = n / 16;
	if (n != 0)
		ft_printuphexa(n);
	write (1, &hexabase[mod], 1);
	i++;
	return (i - j);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		printf("%X\n", ft_atoi(argv[1]));
		ft_printuphexa(ft_atoi(argv[1]));
		return (0);
	}
}
*/