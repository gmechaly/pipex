/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:51:15 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:18:40 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((ptr[i] <= '\r' && ptr[i] >= '\t') || ptr[i] == ' ')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10;
		result = result + ptr[i] - '0';
		i++;
	}
	return (sign * result);
}

/*#include <stdio.h>

int  main(int argc, char **argv)
{
	if (argc != 2)
		return(0);
	else
		printf("%d\n", ft_atoi(argv[1]));
	return (0);
}*/