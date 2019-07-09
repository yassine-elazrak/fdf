/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:19:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/04 19:29:10 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_00(t_init **lst, char *name)
{
	t_init	*init;

	init = *lst;
	init->h_t = 0;
	init->w_t = 0;
	init->name_of_file = ft_strdup(name);
	ft_get_line(lst);
	init->zoom = 10;
	init->a = 220;
	init->b = 360;
	init->z = 0;
	init->rx = 0;
	init->ry = 0;
	init->rz = 0;
	init->ox = 0;
	init->color = 0;
	init->h = 0;
	init->oy = 0;
	init->oz = 0;
	init->g_c = 55;
	init->b_c = 55;
}

int			main(int argc, char **argv)
{
	t_init	*init;
	int		s_l;
	int		bpp;
	int		end;

	if ((argc > 2 || argc < 2) || (!ft_strstr(argv[1], "fdf")))
		ft_put_error();
	if (!(init = (t_init *)malloc(sizeof(t_init))))
		return (0);
	ft_00(&init, argv[1]);
	init->ptr = mlx_init();
	init->win = mlx_new_window(init->ptr, WIDTH, HEIGHT, "fdf");
	init->img = mlx_new_image(init->ptr, WIDTH, HEIGHT);
	init->str_img = (int *)mlx_get_data_addr(init->img, &s_l, &bpp, &end);
	ft_pint_lst(init);
	mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
	mlx_hook(init->win, 2, 0, ft_key, init);
	mlx_mouse_hook(init->win, ft_mousse, init);
	mlx_loop(init->ptr);
	ft_free_lst(&init);
	free(init->name_of_file);
	free(init);
	return (0);
}
