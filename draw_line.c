/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 08:45:51 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/04 18:22:47 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	char		color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;
	return (*(int*)color);
}

void			ft_put_pixle(int x, int y, t_point *lst, t_init *init)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	if (init->color == 0)
	{
		init->str_img[x + (y * WIDTH)] = ft_rgb(((lst->z1) * 25 % 256),
		init->g_c % 256, init->b_c % 256);
	}
	else if (lst->z1 == 0 && lst->z2 == 0)
		init->str_img[x + (y * WIDTH)] = ft_rgb(199, 210, 200);
	else
		init->str_img[x + (y * WIDTH)] = init->color;
}

static	void	ft_line_x(t_point *lst, t_init *init, int dx, int dy)
{
	int			error;
	int			x;
	int			y;
	int			i;

	x = lst->x1;
	y = lst->y1;
	i = 0;
	error = dx / 2;
	while (i < dx)
	{
		x += lst->xinc;
		error += dy;
		if (error > dx)
		{
			error -= dx;
			y += lst->yinc;
		}
		ft_put_pixle(x, y, lst, init);
		i++;
	}
	ft_put_pixle(x, y, lst, init);
	ft_put_pixle(lst->x1, lst->y1, lst, init);
}

static	void	ft_line_y(t_point *lst, t_init *init, int dx, int dy)
{
	int			error;
	int			x;
	int			y;
	int			i;

	x = lst->x1;
	y = lst->y1;
	i = 0;
	error = dy / 2;
	while (i < dy)
	{
		y += lst->yinc;
		error += dx;
		if (error > dy)
		{
			error -= dy;
			x += lst->xinc;
		}
		ft_put_pixle(x, y, lst, init);
		i++;
	}
	ft_put_pixle(x, y, lst, init);
	ft_put_pixle(lst->x1, lst->y1, lst, init);
}

void			ft_line(t_point *lst, t_init *init)
{
	int			dx;
	int			dy;

	ft_modif_corrdone(lst, init);
	dx = abs(lst->x2 - lst->x1);
	dy = abs(lst->y2 - lst->y1);
	if (lst->x1 < lst->x2)
		lst->xinc = 1;
	else
		lst->xinc = -1;
	if (lst->y1 < lst->y2)
		lst->yinc = 1;
	else
		lst->yinc = -1;
	if (dx > dy)
		ft_line_x(lst, init, dx, dy);
	else
		ft_line_y(lst, init, dx, dy);
}
