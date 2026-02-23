/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:22:21 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/13 18:48:13 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	bb;
	int				i;

	if (!s)
		return (NULL);
	bb = (unsigned char) c;
	i = 0;
	while (n--)
		*(unsigned char *)s++ = bb;
	return (s);
}

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	i;
// 	unsigned char	*p;

// 	if (!s)
// 		return (NULL);
// 	p = (unsigned char *)s;
// 	i = (unsigned char)c;
// 	while (n--)
// 	{
// 		*p++ = i;
// 	}
// 	return (s);
// }

// int	main()
// {
// 	char	ptr[] = "Hello me banana";
// 	ptr[15] = '\0';
// 	char	i = 'a';
// 	ft_memset(ptr, i, 5);
// 	printf("%s\n", ptr); 
// }
