/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:53:01 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/07 14:53:02 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	del(char ***n, int w)
{
	while (--w)
		ft_strdel(&(*n[w]));
	ft_memdel((void*)n);
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**n;
	char	*t;
	int		w;

	if (s && !(w = 0))
	{
		t = (char*)s;
		while (*t++)
			if (*(t - 1) != c && w++ != -1 && !(t = ft_strchr(t, c)))
				break ;
		if (!(n = (char**)malloc(sizeof(char*) * w + 1)))
			return (NULL);
		n[w] = NULL;
		if (w && !(w = 0))
			while (*s++)
				if ((t = (char*)(s - 1)) && *(s - 1) != c && s-- != NULL)
				{
					while (*(s) != c && *(s))
						s++;
					if ((n[w++] = ft_strsub(t, 0, (s - t))) ? 0 : del(&n, w))
						return (NULL);
				}
		return (n);
	}
	return (NULL);
}
