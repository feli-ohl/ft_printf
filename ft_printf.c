/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:44:14 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:07:58 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

static t_flags	ft_parse_flags(const char *format, size_t *i)
{
	t_flags	flags;

	flags = ft_init_flags();
	while (format[*i] == '#' || format[*i] == ' ' || format[*i] == '+')
	{
		if (format[*i] == '#')
			flags.hash = 1;
		if (format[*i] == ' ')
			flags.space = 1;
		if (format[*i] == '+')
			flags.plus = 1;
		(*i)++;
	}
	return (flags);
}

static int	ft_parse_format(const char *format, size_t *i, va_list *args)
{
	int		count;
	t_flags	flags;

	count = 0;
	flags = ft_parse_flags(format, i);
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (format[*i] == 's')
		count += ft_print_string(va_arg(*args, char *));
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(*args, void *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_integer(va_arg(*args, int), flags);
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format[*i] == 'x')
		count += ft_print_hex(va_arg(*args, unsigned int), flags, 0);
	else if (format[*i] == 'X')
		count += ft_print_hex(va_arg(*args, unsigned int), flags, 1);
	else if (format[*i] == '%')
		count += ft_print_char('%');
	else
		count += 0;
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse_format(format, &i, &args);
		}
		else
			count += ft_print_char(format[i]);
		if (format[i] == '\0')
			break ;
		i++;
	}
	va_end(args);
	return (count);
}
