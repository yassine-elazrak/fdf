/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 09:17:05 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/09 11:51:01 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_put_cor_of_tab(t_init **lst, char **str, int j)
{
	t_init		*init;
	int			count;
	char		*t;
	t_cor		*tmp;

	count = 0;
	init = *lst;
	while (str[count])
	{
		if (!(tmp = (t_cor *)malloc(sizeof(t_cor))))
			return ;
		if ((t = ft_strchr(str[count], ',')))
			tmp->color = ft_atoi_0x(t + 3);
		else
			tmp->color = 0;
		tmp->x = count;
		tmp->y = j;
		tmp->z = ft_atoi(str[count]);
		init->tab[j][count] = tmp;
		count++;
	}
}

static int		ft_count(char **str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_put_error(void)
{
	ft_putendl("file not valable");
	exit(1);
}

static	void	ft_get_valuer_of_line(t_init **lst)
{
	char	*str;
	t_init	*init;
	char	**ptr;
	int		position;
	int		fd[2];

	init = *lst;
	position = 0;
	fd[0] = open(init->name_of_file, O_RDONLY);
	while (get_next_line(fd[0], &str))
	{
		ptr = ft_strsplit(str, ' ');
		fd[1] = ft_count(ptr);
		if (position != 0 && fd[1] < init->w_t)
			ft_put_error();
		if (position == 0)
			init->w_t = fd[1];
		if (!(init->tab[position] = (t_cor **)malloc(sizeof(t_cor*)
			* fd[1] + 1)))
			return ;
		ft_put_cor_of_tab(lst, ptr, position);
		position++;
		ft_free_tab_2(ptr);
	}
	close(fd[0]);
}

void			ft_get_line(t_init **lst)
{
	int			i;
	int			fd;
	t_init		*init;
	char		*str;

	i = 0;
	init = *lst;
	if (0 > (fd = open(init->name_of_file, O_RDONLY)))
	{
		ft_putendl("file not exit");
		exit(1);
	}
	while (get_next_line(fd, &str))
	{
		free(str);
		i++;
	}
	init->h_t = i;
	if (!(init->tab = (t_cor ***)malloc(sizeof(t_cor **) * (i + 1))))
		return ;
	ft_get_valuer_of_line(lst);
	close(fd);
}
