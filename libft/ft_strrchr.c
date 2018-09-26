/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:42:00 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/29 19:42:00 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	while (len--)
		if (s[len] == (char)c)
			return ((char*)&s[len]);
	return (NULL);
}
