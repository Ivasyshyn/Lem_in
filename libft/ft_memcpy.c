/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:41:20 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/27 19:41:21 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tdst;

	if (dst == src)
		return (dst);
	tdst = (unsigned char*)dst;
	while (n--)
		*(unsigned char*)tdst++ = *(unsigned char*)src++;
	return (dst);
}
