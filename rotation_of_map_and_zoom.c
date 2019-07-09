/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_of_map_and_zoom.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:05:50 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/09 11:52:28 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int x_1;
	int y_1;

	x_1 = *x;
	y_1 = *y;
	*x = (x_1 - y_1) * cos(0.523599);
	*y = -z + (x_1 + y_1) * sin(0.523599);
}

void	ft_rot_y(t_point **list, t_init *init)
{
	t_point *lst;
	int		x1;
	int		x2;
	int		z1;
	int		z2;

	lst = *list;
	x1 = lst->x1;
	x2 = lst->x2;
	z1 = lst->z1;
	z2 = lst->z2;
	lst->x1 = x1 * cos(init->oy) + z1 * sin(init->oy);
	lst->z1 = -x1 * sin(init->oy) + z1 * cos(init->oy);
	lst->x2 = x2 * cos(init->oy) + z2 * sin(init->oy);
	lst->z2 = -x2 * sin(init->oy) + z2 * cos(init->oy);
}

void	ft_rot_x(t_point **list, t_init *init)
{
	t_point *lst;
	int		z1;
	int		z2;
	int		y1;
	int		y2;

	lst = *list;
	z1 = lst->z1;
	z2 = lst->z2;
	y1 = lst->y1;
	y2 = lst->y2;
	lst->y1 = y1 * cos(init->ox) + z1 * cos(init->ox);
	lst->z1 = -y1 * sin(init->ox) + z1 * cos(init->ox);
	lst->y2 = y2 * cos(init->ox) + z2 * cos(init->ox);
	lst->z2 = y2 * sin(init->ox) + z2 * cos(init->ox);
}

void	ft_rot_z(t_point **list, t_init *init)
{
	t_point *lst;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	lst = *list;
	x1 = lst->x1;
	x2 = lst->x2;
	y1 = lst->y1;
	y2 = lst->y2;
	lst->x1 = x1 * cos(init->oz) - y1 * cos(init->oz);
	lst->y1 = x1 * sin(init->oz) + y1 * cos(init->oz);
	lst->x2 = x2 * cos(init->oz) - y2 * cos(init->oz);
	lst->y2 = x2 * sin(init->oz) + y2 * cos(init->oz);
}

void	ft_modif_corrdone(t_point *lst, t_init *init)
{
	lst->x2 = lst->x2 * init->zoom;
	lst->x1 = lst->x1 * init->zoom;
	lst->y1 = lst->y1 * init->zoom;
	lst->y2 = lst->y2 * init->zoom;
	if (init->i == 2)
	{
		iso(&lst->x1, &lst->y1, init->z);
		iso(&lst->x2, &lst->y2, init->z);
	}
	if (init->rz != 0)
		ft_rot_z(&lst, init);
	else if (init->rx != 0)
		ft_rot_x(&lst, init);
	else if (init->ry != 0)
		ft_rot_y(&lst, init);
	lst->x2 += init->a;
	lst->x1 += init->a;
	lst->y1 += init->b;
	lst->y2 += init->b;
}
