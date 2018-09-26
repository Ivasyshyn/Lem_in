/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:13:27 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/29 20:13:28 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (*little == '\0')
		return ((char*)big);
	while (*big++)
		if (ft_strncmp(big - 1, little, ft_strlen(little)) == 0)
			return ((char*)big - 1);
	return (NULL);
}
