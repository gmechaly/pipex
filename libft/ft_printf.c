/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:28:02 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:33 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*printf renvoie le nombre de caracteres affiches sans compter l'octet final
 '\0'.
  Tout les caracteres differents d'un % et pas places apres un % sont print
  doit implementer %c (char), %s (string), %p (void * en hexa), %d (decimal),
  %i (entier), %u (decimal non signe), %xX (nombre hexa lowercase ou uppercase),
  %% (print %).
  --{va_start initialise le pointeur va_list ptr pour qu'il 
  pointe sur la derniere variable fixe}
  --{va_arg accede a la variable pointee par ptr et fait 
  pointer ptr sur la variable suivante}
  --{va_copy permet de dupliquer l'état d'une structure de données 
  de type va_list. Cette macro sera, par exemple, utile si vous 
  devez parcourir à plusieurs reprise la liste de paramètres durant
  l'exécution de la fonction associée.} 
  --{va_end termine le parcourt des arguments} */

int	ft_if(const char str, va_list ptr)
{
	int		i;

	i = 0;
	if (str == 'c')
		i += ft_printchar(va_arg(ptr, int));
	else if (str == 's')
		i += ft_printstr(va_arg(ptr, char *));
	else if (str == 'i' || str == 'd')
		i += ft_printnbr(va_arg(ptr, int));
	else if (str == 'p')
		i += ft_printptr(va_arg(ptr, void *));
	else if (str == 'u')
		i += ft_printunint(va_arg(ptr, unsigned int));
	else if (str == 'x')
		i += ft_printlowhexa(va_arg(ptr, unsigned long long int));
	else if (str == 'X')
		i += ft_printuphexa(va_arg(ptr, unsigned long long int));
	else if (str == '%')
		i += ft_printchar('%');
	else
		i += ft_printchar('%') + ft_printchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		count;
	va_list	ptr;

	i = 0;
	j = 0;
	count = 0;
	va_start (ptr, str);
	while (str[i + j])
	{
		if (str[i + j] != '%')
		{
			write(1, &str[i + j], 1);
			i++;
		}
		else
		{
			j++;
			count += ft_if (str[i + j], ptr);
			j++;
		}
	}
	va_end (ptr);
	return (count + i);
}

/*#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(void)
{
	int	i;

	i = ft_printf(" %r %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf(" %d\n", i);
	i = printf(" %r %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf(" %d\n", i);
	return (0);
}
*/