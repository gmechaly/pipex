/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:54:37 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:38 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*uchar_src;
	unsigned char	*uchar_dest;

	uchar_src = (unsigned char *) src;
	uchar_dest = (unsigned char *) dest;
	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		uchar_dest[i] = uchar_src[i];
		i++;
	}
	return (dest);
}
