/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:02:51 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/06 18:02:51 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s && !(i = 0))
	{
		if (!(new = ft_strnew(len)))
			return (NULL);
		while (len--)
			new[i++] = s[start++];
		return (new);
	}
	return (NULL);
}
