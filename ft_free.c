/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:38:32 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/09 14:32:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_tab_2(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		ft_free_lst(t_init **init)
{
	t_init	*lst;
	int		i;
	int		j;
	t_cor	*new;

	j = 0;
	lst = *init;
	while (j < lst->h_t)
	{
		i = 0;
		while (i < lst->w_t)
		{
			new = lst->tab[j][i];
			free(new);
			i++;
		}
		j++;
	}
	i = 0;
	while (++i < lst->h_t)
	{
		free(lst->tab[i]);
	}
	free(lst->tab);
	free(lst->name_of_file);
}

int			ft_convert_0x(int i, int s, char *str)
{
	int		a;

	a = 0;
	while (ft_isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (ft_isdigit(str[i]))
			a = a * 10 + (str[i] - '0');
		else if ((str[i] >= 'a' && str[i] <= 'f'))
			a = a * 10 + (str[i] - 'a' + 10);
		else if ((str[i] >= 'A' && str[i] <= 'F'))
			a = a * 10 + (str[i] - 'A' + 10);
		i++;
	}
	return ((int)(a * s));
}

int			ft_atoi_0x(char *str)
{
	long	a;
	int		s;
	int		i;

	i = 0;
	s = 1;
	a = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		i++;
		s = -1;
	}
	if (str[i] == '+')
		i++;
	return (ft_convert_0x(i, s, str));
}
