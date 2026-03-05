/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:36:49 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/22 18:38:17 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uchar_s;
	unsigned char	uchar_c;

	uchar_s = (unsigned char *) s;
	uchar_c = c;
	while (n > 0)
	{
		if (*uchar_s == uchar_c)
			return ((void *)uchar_s);
		uchar_s++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*s;

	s = "012345";
	ft_memchr(s, 2, 3);
	ft_memchr(s, 2 + 256, 3);
}
*/