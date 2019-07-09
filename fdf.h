/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 09:26:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/04 17:58:16 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 500

typedef struct	s_cor
{
	double x;
	double y;
	double z;
	double color;
}				t_cor;

typedef struct	s_init
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*str_img;
	int			w_t;
	int			h_t;
	char		*name_of_file;
	double		z;
	int			a;
	int			b;
	int			zoom;
	double		ox;
	double		oy;
	double		oz;
	int			rx;
	int			ry;
	int			rz;
	int			i;
	int			color;
	int			h;
	int			g_c;
	int			b_c;
	t_cor		***tab;
}				t_init;

typedef struct	s_point
{
	int	x1;
	int y1;
	int x2;
	int y2;
	int z1;
	int z2;
	int yinc;
	int xinc;
}				t_point;

void			ft_line(t_point *lst, t_init *init);
void			ft_get_line(t_init **lst);
int				ft_key(int code_key, t_init *ptr);
int				ft_mousse(int button, int x, int y, t_init *init);
void			ft_pint_lst(t_init *init);
void			ft_get_line(t_init **lst);
void			ft_modif_corrdone(t_point *lst, t_init *init);
void			ft_00(t_init **lst, char *name);
void			ft_free_lst(t_init **init);
void			ft_free_tab_2(char **str);
int				ft_atoi_0x(char *str);
void			ft_put_error(void);
#endif
