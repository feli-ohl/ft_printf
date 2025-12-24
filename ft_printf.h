/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:12:22 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:01:31 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	hash;	// '#'
	int	space;	// ' '
	int	plus;	// '+'
}	t_flags;

int	ft_printf(char const *format, ...);

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_integer(int nbr, t_flags flags);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(unsigned int nbr, t_flags flags, int upper);

#endif