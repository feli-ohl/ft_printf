/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:06:32 by foehler           #+#    #+#             */
/*   Updated: 2025/12/19 18:22:44 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	len;

	len = ft_strlen(s1) + 1;
	pointer = (char *)malloc(len * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	ft_memcpy(pointer, s1, len);
	return (pointer);
}
