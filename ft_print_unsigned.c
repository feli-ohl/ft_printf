/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:42:50 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:15:50 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int		count;
	char	num;

	count = 0;
	if (nbr >= 10)
		count += ft_print_unsigned(nbr / 10);
	num = (nbr % 10) + '0';
	count += write(1, &num, 1);
	return (count);
}
