/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:03:52 by foehler           #+#    #+#             */
/*   Updated: 2025/12/20 14:06:41 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	i;

	size = ft_lstsize(lst);
	i = 0;
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
