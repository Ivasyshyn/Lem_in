/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:20:26 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/06 18:20:26 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 && s2)
		if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcpy(new, s1);
			ft_strcpy(&new[ft_strlen(s1)], s2);
			return (new);
		}
	return (NULL);
}
