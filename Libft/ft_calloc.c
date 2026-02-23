/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:01:23 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/13 18:42:29 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;
	size_t	i;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (num && SIZE_MAX / num < size)
		return (NULL);
	i = 0;
	array = malloc(num * size);
	if (!array)
		return (NULL);
	ft_bzero(array, num * size);
	return (array);
}
