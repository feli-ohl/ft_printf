/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:39:43 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:11:17 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_recursive(const unsigned long nbr, const char *base)
{
	int	count;

	if (nbr < 16)
	{
		write(1, &base[nbr], 1);
		return (1);
	}
	count = ft_print_hex_recursive(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	return (count + 1);
}

int	ft_print_pointer(void *ptr)
{
	int				count;
	unsigned long	nbr;
	char			*base;

	if (ptr == NULL)
		return (write(1, "0x0", 3));
	count = 0;
	nbr = (unsigned long)ptr;
	base = "0123456789abcdef";
	count += ft_print_string("0x");
	count += ft_print_hex_recursive(nbr, base);
	return (count);
}
