/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:02:52 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/04 16:35:42 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_mousse(int button, int x, int y, t_init *init)
{
	if (button == 1)
	{
		init->a = x;
		init->b = y;
		mlx_clear_window(init->ptr, init->win);
		ft_bzero(init->str_img, WIDTH * HEIGHT * 4);
		ft_pint_lst(init);
		mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
	}
	return (0);
}

t_point			*ft_lst_point(int x1, int y1, int x2, int y2)
{
	t_point *lst;

	if (!(lst = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	lst->x1 = x1;
	lst->y1 = y1;
	lst->x2 = x2;
	lst->y2 = y2;
	return (lst);
}

void			ft_print_point(t_point *lst, int j, int i, t_init *init)
{
	if (j < init->h_t - 1)
	{
		lst = ft_lst_point(init->tab[j][i]->x - init->tab[j][i]->z * init->z,
				init->tab[j][i]->y - init->tab[j][i]->z * init->z,
				init->tab[j][i]->x - init->tab[j + 1][i]->z * init->z,
				init->tab[j + 1][i]->y - init->tab[j + 1][i]->z * init->z);
		lst->z1 = init->tab[j][i]->z;
		init->color = init->tab[j][i]->color;
		lst->z2 = init->tab[j + 1][i]->z;
		ft_line(lst, init);
		free(lst);
	}
	if (i < init->w_t - 1)
	{
		lst = ft_lst_point(init->tab[j][i]->x - init->tab[j][i]->z * init->z,
				init->tab[j][i]->y - init->tab[j][i]->z * init->z,
				init->tab[j][i + 1]->x - init->tab[j][i + 1]->z * init->z,
				(init->tab[j][i]->y) - init->tab[j][i + 1]->z * init->z);
		lst->z1 = init->tab[j][i]->z;
		init->color = init->tab[j][i]->color;
		lst->z2 = init->tab[j][i + 1]->z;
		ft_line(lst, init);
		free(lst);
	}
}

void			ft_pint_lst(t_init *init)
{
	int			i;
	int			j;
	t_point		*lst;

	j = -1;
	while (++j < init->h_t)
	{
		i = -1;
		while (++i < init->w_t)
			ft_print_point(lst, j, i, init);
		if (j < init->h_t - 2 && i < init->w_t - 1)
		{
			lst = ft_lst_point((init->tab[j][i]->x)
					- init->tab[j + 1][i]->z * init->z,
					init->tab[j + 1][i]->y - init->tab[j + 1][i]->z * init->z,
					init->tab[j][i]->x - init->tab[j][i]->z * init->z,
					init->tab[j][i]->y - init->tab[j][i]->z * init->z);
			lst->z1 = init->tab[j + 1][i]->z;
			init->color = init->tab[j][i]->color;
			lst->z2 = init->tab[j][i]->z;
			ft_line(lst, init);
			free(lst);
		}
	}
}
