/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:54:44 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/28 18:54:44 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tdst;

	tdst = (unsigned char*)dst;
	if (dst > src)
		while (len--)
			tdst[len] = *(unsigned char*)&src[len];
	else
		while (len--)
			*tdst++ = *(unsigned char*)src++;
	return (dst);
}
