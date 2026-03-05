/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:19:53 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:43 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*hess;

	hess = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		hess[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
