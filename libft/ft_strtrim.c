/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:29:11 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/06 18:29:12 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	len;

	if (s && !(start = 0))
	{
		len = ft_strlen(s);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		if (start == ft_strlen(s))
			return (ft_strnew(0));
		while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
			len--;
		if (!(new = ft_strsub(s, start, len - start)))
			return (NULL);
		return (new);
	}
	return (NULL);
}
