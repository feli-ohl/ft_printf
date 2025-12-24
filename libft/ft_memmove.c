/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:31:08 by foehler-          #+#    #+#             */
/*   Updated: 2025/12/22 11:30:48 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	if (temp_dest > temp_src && temp_dest < temp_src + n)
	{
		while (n > 0)
		{
			n--;
			temp_dest[n] = temp_src[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
