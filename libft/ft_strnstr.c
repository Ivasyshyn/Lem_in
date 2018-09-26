/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:20:10 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/29 22:20:10 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char*)big);
	while (*big++ != '\0' && !(len-- < ft_strlen(little)))
		if (ft_strncmp(big - 1, little, ft_strlen(little)) == 0)
			return ((char*)big - 1);
	return (NULL);
}
