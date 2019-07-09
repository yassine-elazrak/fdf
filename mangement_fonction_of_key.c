/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mangement_fonction_of_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:52:11 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/09 14:29:48 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_info_key_3(int s, t_init *lst)
{
	if (s == 15)
		lst->z += 0.2;
	else if (s == 3)
		lst->z -= 0.2;
	else if (s == 69)
		lst->zoom += 1;
	else if (s == 78)
	{
		if (lst->zoom > 0)
			lst->zoom -= 1;
	}
	else
		return (0);
	return (1);
}

int			ft_info_key_1(int s, t_init *lst)
{
	char	*str;

	if (s == 126)
		lst->b -= 10;
	else if (s == 125)
		lst->b += 10;
	else if (s == 124)
		lst->a += 10;
	else if (s == 123)
		lst->a -= 10;
	else if (s == 82)
	{
		str = ft_strdup(lst->name_of_file);
		ft_free_lst(&lst);
		ft_00(&lst, str);
		free(str);
	}
	else
		return (0);
	return (1);
}

int			ft_info_key_2(int s, t_init *lst)
{
	if (s == 6)
	{
		lst->oz += 0.1;
		lst->rz = 2;
		lst->rx = 0;
		lst->ry = 0;
	}
	else if (s == 16)
	{
		lst->ox += 0.1;
		lst->rx = 2;
		lst->rz = 0;
		lst->ry = 0;
	}
	else if (s == 7)
	{
		lst->oy += 0.1;
		lst->ry = 2;
		lst->rz = 0;
		lst->rx = 0;
	}
	else
		return (0);
	return (1);
}

int			ft_info_key_4(int s, t_init *lst)
{
	if (s == 34)
		lst->i = 2;
	else if (s == 35)
		lst->i = 0;
	else if (s == 0)
		lst->g_c += 2;
	else if (s == 1)
		lst->b_c += 2;
	else
		return (0);
	return (1);
}

int			ft_key(int code_key, t_init *init)
{
	if (code_key == 53)
		exit(0);
	if (ft_info_key_1(code_key, init) || ft_info_key_2(code_key, init)
			|| ft_info_key_3(code_key, init) || ft_info_key_4(code_key, init))
	{
		mlx_clear_window(init->ptr, init->win);
		ft_bzero(init->str_img, WIDTH * HEIGHT * 4);
		ft_pint_lst(init);
		mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
	}
	return (0);
}
