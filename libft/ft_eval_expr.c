/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:26:23 by sivasysh          #+#    #+#             */
/*   Updated: 2017/11/21 17:26:24 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(t_elem **elm)
{
	while ((*elm)->next)
		del(&(*elm)->next);
	free(*elm);
	*elm = NULL;
}

static t_elem	*ft_elemnew(int nbr, char sign)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->nbr = nbr;
	new->sign = sign;
	new->next = NULL;
	return (new);
}

static int		ft_elemadd(t_elem *elm, int nbr, char sign)
{
	if (elm->next && ft_elemadd(elm->next, nbr, sign))
	{
		del(&elm);
		return (1);
	}
	if (!elm->next)
	{
		if ((sign == '+' || sign == '-') &&
			!(elm->next = ft_elemnew(nbr, sign)))
			return (1);
		else if (sign == '*' || sign == '/' || sign == '%')
		{
			if (sign != '*' && nbr == 0)
			{
				ft_putstr((sign == '%') ? "Remainder by zero is undefined\n" :
					"Division by zero is undefined\n");
				return (1);
			}
			else
				elm->nbr = OPER(elm->nbr, sign, nbr);
		}
	}
	return (0);
}

static int		ft_elemsum(t_elem *elm)
{
	int	res;

	if (!elm)
		return (0);
	res = ft_elemsum(elm->next);
	return (res += elm->nbr);
}

int				ft_eval_expr(char *expr, int *i)
{
	t_elem		*list;
	char		sign;
	int			crntnbr;

	crntnbr = 0;
	list = ft_elemnew(0, '+');
	sign = '+';
	while (expr[*i] != '\0' && expr[*i] != ')')
	{
		if (ft_isdigit(expr[*i]) || (expr[*i] == '-' &&
			(ft_isdigit(expr[*i + 1]))))
		{
			crntnbr = ft_atoi(expr + *i);
			if ((ft_elemadd(list, crntnbr, sign)))
				return (0);
			*i += (ft_ch_in_nb(crntnbr)) - 1;
		}
		if (SIGN('+') || SIGN('-') || SIGN('*') || SIGN('/') || SIGN('%'))
			sign = expr[*i];
		if (expr[*i] == '(' && ((*i) += 1 != -1))
			ft_elemadd(list, ft_eval_expr(expr, i), sign);
		(*i)++;
	}
	return (ft_elemsum(list));
}
