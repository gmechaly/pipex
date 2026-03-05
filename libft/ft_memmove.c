/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:29:50 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:41 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*uchar_src;
	unsigned char	*uchar_dest;

	if (dest == NULL && src == NULL)
		return (0);
	uchar_src = (unsigned char *) src;
	uchar_dest = (unsigned char *) dest;
	if (src >= dest)
	{
		while (n-- != 0)
			*uchar_dest++ = *uchar_src++;
	}
	else if (src < dest)
	{
		uchar_dest = uchar_dest + n - 1;
		uchar_src = uchar_src + n - 1;
		while (n--)
			*uchar_dest-- = *uchar_src--;
	}
	return (dest);
}

/*int	main(void)
{
	const void *src = "123456";
	void *dest = (void *) &src[2];

	ft_memmove(dest, src, 4);
	return (0);
}*/