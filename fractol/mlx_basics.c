/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:29:32 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/28 21:03:51 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	my_mlx_put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_all_mlx *my_mlx_set(char *wind_name, t_size_wind *wind_size, t_cmplx_nb *cmplx_c)
{
	t_all_mlx	*all_mlx;

	all_mlx = calloc(1, sizeof(*all_mlx));
	if (!all_mlx)
		return ((void *)0);
	all_mlx->mlx = mlx_init();
	all_mlx->wind_hei = wind_size->height;
	all_mlx->wind_wid = wind_size->width;
	all_mlx->cmplx_C = cmplx_c;
	all_mlx->mlx_wind = mlx_new_window(all_mlx->mlx, wind_size->width,
		 wind_size->height, wind_name);
	all_mlx->mlx_img = my_mlx_img_set(all_mlx);
	free(wind_size);
	if (!all_mlx->mlx_img)
		return ((void *)0);
	return (all_mlx);
}

t_data *my_mlx_img_set( t_all_mlx *all_mlx)
{
	t_data	*point_img;

	point_img = calloc(1, sizeof(*point_img));
	if (!point_img)
	return ((void *)0);
	point_img->img = mlx_new_image(all_mlx->mlx, all_mlx->wind_wid,
		 all_mlx->wind_hei);
	point_img->addr = mlx_get_data_addr(point_img->img,
			&point_img->bits_per_pixel, &point_img->line_length,
			&point_img->endian);
	return (point_img);
}

/*

Tentative cercle pas ouf 

int x_center;
	int y_center;
	int x;
	int y;
	double x_side;
	double y_side;
	int r;

	r = 100;
	x_center = 500;
	y_center = 500;
	x = x_center - r;
	y = y_center - r;
	while (y <= y_center + r)
	{
		while (x <= x_center + r)
		{
			x_side = x_center - x;
			y_side = y_center - y;
			printf("x_side = %f\n", x_side * x_side);
			if (x_side * x_side + y_side * y_side == r * r)
			{
				my_mlx_put_pxl(&img, x, y ,0x00FF0000);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			x++;
		}
		x = x_center - r;
		y++;
	}


*/