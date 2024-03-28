/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:45:00 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/28 23:55:15 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


int calc_mandel(double x, double y, t_all_mlx *mlx_all)
{
	int			nb_try;
	int			i;
	double		x_tmp;
	
	i = 1;
	nb_try = 80;
	mlx_all->cmplx_C = dbl_to_cmplx(((x - mlx_all->wind_wid / 2 +
		mlx_all->origin_x) / (mlx_all->wind_wid /4)) * mlx_all->zoom,
			((y - mlx_all->wind_hei / 2 + mlx_all->origin_y) / (mlx_all->wind_wid /4))
				 * mlx_all->zoom, 0);
	if(!mlx_all->cmplx_C)
		return(hook_destroy(mlx_all));
	x = 0;
	y = 0;
	while (x < 2 && x > -2 && ++i < nb_try)
	{
		x_tmp = x;
		x = pow(x, 2) - pow(y, 2) + mlx_all->cmplx_C->nb_r;
		y = (2 * x_tmp * y) + mlx_all->cmplx_C->nb_i;
	}
	free(mlx_all->cmplx_C);
	mlx_all->cmplx_C = (void *)0;
	return (i);
}


int calc_julia(double x, double y, t_all_mlx *mlx_all)
{
	int			nb_try;
	int			i;
	double		x_tmp;
	
	i = 1;
	nb_try = 80;
	x = ((x - mlx_all->wind_wid / 2 + mlx_all->origin_x) / (mlx_all->wind_wid /4)) * mlx_all->zoom;
	y = ((y - mlx_all->wind_hei / 2 + mlx_all->origin_y) / (mlx_all->wind_wid /4)) * mlx_all->zoom;
	while (x < 2 && x > -2 && ++i < nb_try)
	{
		x_tmp = x;
		x = pow(x, 2) - pow(y, 2) + mlx_all->cmplx_C->nb_r;
		y = (2 * x_tmp * y) + mlx_all->cmplx_C->nb_i;
	}
	return (i);
}

int create_fract(t_all_mlx *mlx_all)
{
	double x;
	double y;
	int res;
	
	y = 0;
	x = 0;
	while ( ++y < mlx_all->wind_hei)
	{
		while(++x < mlx_all->wind_wid)
		{
			if (mlx_all->cmplx_C)
				res = calc_julia(x, y, mlx_all);
			else 
				res = calc_mandel(x, y, mlx_all);
			if(res < 80)
				my_mlx_put_pxl(mlx_all->mlx_img, x, y, 0x000000FF + 20 * res);
		}
		x = 0;
	}
	mlx_put_image_to_window(mlx_all->mlx, mlx_all->mlx_wind, mlx_all->mlx_img->img, 0, 0);
	return (1);
}


int begin_mlx(t_size_wind *size_wind, t_cmplx_nb *nb_cmplx_C)
{
	t_all_mlx	*mlx_all;
	
	if(!size_wind)
		return (-1);
	mlx_all = my_mlx_set("It works!", size_wind, nb_cmplx_C);
	mlx_all->origin_x = 0;
	mlx_all->origin_y = 0;
	mlx_all->zoom = 1;
	create_fract (mlx_all);
	mlx_key_hook(mlx_all->mlx_wind, hook_key, mlx_all);
	mlx_hook(mlx_all->mlx_wind, 17, 0L,hook_destroy, mlx_all);
	mlx_mouse_hook(mlx_all->mlx_wind, mouse_hook, mlx_all);		
	mlx_loop(mlx_all->mlx);
	return (1);
}
/*
// x and y neg 
// x and y max;

int start_mandelbrott(t_all_mlx *mlx_all)
{
	double x;
	double y;
	int res;

	y = 0;
	x = 0;
	while (++y < mlx_all->wind_hei)
	{
		while( ++x < mlx_all->wind_wid)
		{
			res = sqnc_mandel(x, y, mlx_all);
			if(res < 80)
				my_mlx_put_pxl(mlx_all->mlx_img, x, y, 0x000000FF + 20 * res);
		}
		x = 0;
	}
	mlx_put_image_to_window(mlx_all->mlx, mlx_all->mlx_wind, mlx_all->mlx_img->img, 0, 0);
	return (1);
}*/
/*
int start_mandelbrot(t_size_wind *size_wind)
{
	t_all_mlx *mlx_mandel;
	double x;
	double y;
	int unit;
	int res;
	
	if(!size_wind)
			return (-1);
	unit = determine_unit(size_wind->width, size_wind->height);
	y = -2 * unit;
	x = -2 * unit;
	mlx_mandel = my_mlx_set("Coucou Mandelbrot !", size_wind->width, size_wind->height);
	mlx_key_hook(mlx_mandel->mlx_wind, hook_close, mlx_mandel);
	mlx_hook(mlx_mandel->mlx_wind, 17, 0L,hook_destroy, mlx_mandel);
	while (size_wind->height / 2 + ++y < size_wind->height / 2 + 2 * unit)
	{
		while(size_wind->width / 2 + ++x < size_wind->width / 2 + 2 * unit)
		{
			res = sqnce_fract(dbl_to_cmplx(0, 0, 0), dbl_to_cmplx(x, y, unit));
			if(res < 200)
				my_mlx_put_pxl(mlx_mandel->mlx_img, size_wind->width / 2 + x, size_wind->height / 2 - y, 0x000000FF + 20 * res);
		}
		x = -2 * unit;
	}
	mlx_put_image_to_window(mlx_mandel->mlx, mlx_mandel->mlx_wind, mlx_mandel->mlx_img->img, 0, 0);
	mlx_loop(mlx_mandel->mlx);
	return (1);
}

int start_julia(t_size_wind * size_wind, t_cmplx_nb *nb_cmplx_C)
{
	t_all_mlx *mlx_julia;
	int x;
	int y;
	int unit;
	int res;

	unit = 270;
	y = -2 * unit;
	x = -2 * unit;
	if (size_wind)
		free(size_wind);
	mlx_julia = my_mlx_set("Coucou Julia !", 2000, 2000);
	mlx_key_hook(mlx_julia->mlx_wind, hook_close, mlx_julia);
	mlx_hook(mlx_julia->mlx_wind, 17, 0L,hook_destroy, mlx_julia);
	while (540 + ++y < 540 + 2 * unit)
	{
		while(960 + ++x < 960 + 2 * unit)
		{
			res = sqnce_fract(dbl_to_cmplx(x, y, unit), nb_cmplx_C);
			if(res < 200)
				my_mlx_put_pxl(mlx_julia->mlx_img, 960 + x, 540 - y, 0x000000FF + 20*res);
		}
		x = -2 * unit;
	}
	free(nb_cmplx_C);
	mlx_put_image_to_window(mlx_julia->mlx, mlx_julia->mlx_wind, mlx_julia->mlx_img->img, 0, 0);
	mlx_loop(mlx_julia->mlx);
	return (1);
}

//	x_ori = 960;
//	y_ori=	540;
*/
/*
TO DO LIST

- Gestion des couleurs pour un meilleur rendu
- Gestion des segfault ou leaks en sortie de programme
- Gestion et comprehension du hook et de son utilite / utilisation
- Gestion des images (generer de nouvelle images quand il y a un zoom ou que je vais devoir me deplacer dans ma fractale)
- 


*/
/*int create_fract (t_all_mlx *mlx_all)
{
	if (mlx_all->cmplx_C)
	{
		if(start_juliaa(mlx_all) == -1)
			return (free_all_mlx(mlx_all));
	}
	else 
	{
		if(start_mandelbrott(mlx_all) == -1)
			return (free_all_mlx(mlx_all));
	}
	return (1);
}
int change_x_y_with_mouse (int x, int y, t_all_mlx *mlx_all)
{
	//double limit_x_min;
	//double limit_y_min;
	//double limit_x_max;
	//double limit_y_max;
	double	rapport_x;
	double	rapport_y;
	int		unit;

	unit = determine_unit(mlx_all->mlx_size->width, mlx_all->mlx_size->height, mlx_all->mlx_x_y);
	printf("prevx_min = %f, prevy_min = %f\n", mlx_all->mlx_x_y->nb_r, mlx_all->mlx_x_y->nb_i);
	if (!mlx_all || !x || !y)
		return (-1);
	rapport_x =(float)x / (mlx_all->mlx_size->width / 2);
	rapport_y =(float)y / (mlx_all->mlx_size->width / 2);
	printf ("rapport_x = %f, rapport_y = %f\n", rapport_x, rapport_y);
	printf ("mlx_unit_x = %f, mlx_unit_y = %f\n",(float) x / unit, (float) y / unit);
	printf("xmin = %f, y_min = %f\n", mlx_all->mlx_x_y->nb_r, mlx_all->mlx_x_y->nb_i);
	return (1);

}*/