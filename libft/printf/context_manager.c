/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_context_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:19:58 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:19:58 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

void	plugin_extra(char *flags, char **context, char space_sign)
{
	if ((!flags[M] && flags[S] && flags[Z]) || (!flags[N] && !flags[M] &&\
	flags[Z] && flags[P] == (space_sign = '+')))
		**context = space_sign;
	if ((flags[N] && flags[Z]) || flags[7] == 'n')
		**context = '-';
	if (!flags[P] && flags[S])
		**context = ' ';
	if (!flags[N] && ((!flags[P] && flags[S]) ||\
	flags[P] == (space_sign = '+')) && flags[M])
	{
		ft_memmove(*context + 1, *context, ft_strlen(*context + 1));
		**context = space_sign;
	}
}

char	*dig_context_manager(char **context, int value, char *flags)
{
	int		difference;
	char	*space;
	char	space_sign;

	space_sign = ' ';
	if ((flags[S] || flags[P]) && (int)ft_strlen(*context) >= value)
		difference = 1;
	else
		difference = value - (int)ft_strlen(*context);
	space = ft_strnew((size_t)(flags[7] == 'n' ? ++difference : difference));
	if ((flags[N] && flags[Z]) || (flags[N] && flags[Z] && flags[P]) ||\
	flags[7] == 'n')
		**context = '0';
	if (flags[Z] && !flags[M] && value > 0)
		space_sign = '0';
	else if ((flags[P] || (flags[P] && flags[S])) && LEN > value)
		space_sign = '+';
	flags[7] ? ft_memset(space, '0', (size_t)difference) :\
	ft_memset(space, space_sign, (size_t)difference);
	if (flags[P] && !flags[Z] && !flags[N])
		space[ft_strlen(space) - 1] = '+';
	*context = flags[M] == '-' ? ft_strjoin_modified(context, &space) :\
	ft_strjoin_modified(&space, context);
	plugin_extra(flags, context, space_sign);
	return (*context);
}

char	*uni_context_manager(int field, int uni_len, char *flags,\
char **context)
{
	char	*space;

	if (field > uni_len)
	{
		space = ft_strnew((size_t)(field - uni_len));
		ft_memset(space, flags[Z] && !flags[M] ? '0' : ' ',\
		(size_t)(field - uni_len));
		*context = flags[M] ? ft_strjoin_modified(context, &space) :\
		ft_strjoin_modified(&space, context);
	}
	return (*context);
}
