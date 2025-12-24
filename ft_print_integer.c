/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:40:50 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:13:11 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(int nbr, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(nbr);
	if (str == NULL)
		return (0);
	if (flags.plus == 1 && nbr >= 0)
		count += write(1, "+", 1);
	else if (flags.space == 1 && nbr >= 0)
		count += write(1, " ", 1);
	count += ft_print_string(str);
	free(str);
	return (count);
}
