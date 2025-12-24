/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:43:46 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 17:57:03 by foehler          ###   ########.fr       */
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

int	ft_print_hex(unsigned int nbr, t_flags flags, int upper)
{
	int		count;
	char	*base;

	count = 0;
	if (upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr == 0)
		return (write(1, "0", 1));
	if (flags.hash == 1)
	{
		if (upper == 1)
			count += ft_print_string("0X");
		if (upper == 0)
			count += ft_print_string("0x");
	}
	count += ft_print_hex_recursive(nbr, base);
	return (count);
}
