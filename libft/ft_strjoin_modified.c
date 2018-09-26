/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_modified.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_modified(char **s1, char **s2)
{
	char	*new;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = ft_strlen(*s1);
	s2_size = ft_strlen(*s2);
	if (*s1 && *s2)
		if ((new = ft_strnew(s1_size + s2_size)))
		{
			ft_strcpy(new, *s1);
			ft_strcpy(&new[s1_size], *s2);
			ft_memdel((void*)s1);
			ft_memdel((void*)s2);
			return (new);
		}
	return (NULL);
}
