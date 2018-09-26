/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:16:25 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/29 17:16:25 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	if (size > ft_strlen(dst) && (size -= i))
	{
		while (*src && size-- != 1)
			dst[i++] = *src++;
		dst[i] = '\0';
		return (ft_strlen(src) + i);
	}
	return (ft_strlen(src) + size);
}
