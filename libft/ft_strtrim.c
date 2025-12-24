/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:52 by foehler           #+#    #+#             */
/*   Updated: 2025/12/19 20:34:35 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	final;
	char	*trim;

	inicio = 0;
	while (s1[inicio] != '\0' && ft_strchr(set, s1[inicio]) != NULL)
		inicio++;
	final = ft_strlen(s1);
	while (final > inicio && ft_strchr(set, s1[final - 1]) != NULL)
		final--;
	trim = ft_substr(s1, inicio, final - inicio);
	return (trim);
}
