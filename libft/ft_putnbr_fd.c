/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:58:08 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:51 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	u;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		u = '-';
		write (fd, &u, 1);
	}
	u = '0' + n % 10;
	n = n / 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	write (fd, &u, 1);
}

/*int	main(void)
{
	ft_putnbr_fd(0, 2);
	write(2, "\n", 1);
	ft_putnbr_fd(-5, 2);
	write(2, "\n", 1);
	ft_putnbr_fd(-987441, 2);
	write(2, "\n", 1);
	return (0);
}
*/