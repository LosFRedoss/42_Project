/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:45:00 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/20 20:48:55 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int sqnce_fract( t_cmplx_nb *cmplx_z0, t_cmplx_nb *cmplx_C)
{
	t_cmplx_nb *zn;
	int nb_try;
	int i;
	
	i = 0;
	nb_try = 200;
	//printf("cmplx_zo real = %f, cmplx_zo img = %f \n", cmplx_C->nb_r, cmplx_C->nb_i);
	zn = dbl_to_cmplx(cmplx_z0->nb_r, cmplx_z0->nb_i, 0);
	if (!zn)
		return (-1);
	while (zn->nb_r < 2 && zn->nb_r > -2 && ++i < nb_try)
	{
		zn = calc_cmplx_add(calc_cmplx_square(zn), cmplx_C);
		if (!zn)
			return (-1);
		//printf("i = %i, r(zn) = %f, i(zn) = %f\n",i, zn->nb_r, zn->nb_i);
	}
	//printf("i = %i, abs(zn) = %f\n",i, zn->nb_r);
	free(zn);
	free(cmplx_z0);
	return (i);
}
int start_mandelbrott(t_all_mlx *mlx_all, t_size_wind * wind)
{
	double x;
	double y;
	int res;
	int unit;
	
	unit = determine_unit(wind->width, wind->height);
	y = -2 * unit;
	x = -2 * unit;
	while (wind->height / 2 + ++y < wind->height / 2 + 2 * unit)
	{
		while(wind->width / 2 + ++x < wind->width / 2 + 2 * unit)
		{
			res = sqnce_fract(dbl_to_cmplx(0, 0, 0), dbl_to_cmplx(x, y, unit));
			if(res < 200)
				my_mlx_put_pxl(mlx_all->mlx_img, wind->width / 2 + x, wind->height / 2 - y, 0x000000FF + 20 * res);
		}
		x = -2 * unit;
	}
	mlx_put_image_to_window(mlx_all->mlx, mlx_all->mlx_wind, mlx_all->mlx_img->img, 0, 0);
	return (1);
}

int start_juliaa(t_all_mlx *mlx_all, t_size_wind * wind, t_cmplx_nb *nb_cmplx_C)
{
	double x;
	double y;
	int res;
	int unit;
	
	unit = determine_unit(wind->width, wind->height);
	y = -2 * unit;
	x = -2 * unit;
	while (wind->height / 2 + ++y < wind->height / 2 + 2 * unit)
	{
		while(wind->width / 2 + ++x < wind->width / 2 + 2 * unit)
		{
			res = sqnce_fract(dbl_to_cmplx(x, y, unit), nb_cmplx_C);
			if(res < 200)
				my_mlx_put_pxl(mlx_all->mlx_img, wind->width / 2 + x, wind->height / 2 - y, 0x000000FF + 20 * res);
		}
		x = -2 * unit;
	}
	mlx_put_image_to_window(mlx_all->mlx, mlx_all->mlx_wind, mlx_all->mlx_img->img, 0, 0);
	return (1);
}

int begin_mlx(t_size_wind *size_wind, t_cmplx_nb *nb_cmplx_C)
{
	t_all_mlx *mlx_all;
	
	if(!size_wind)
			return (-1);
	print_nb_cmplx(nb_cmplx_C);
	mlx_all = my_mlx_set("It works!", size_wind->width, size_wind->height);
	mlx_key_hook(mlx_all->mlx_wind, hook_close, mlx_all);
	mlx_hook(mlx_all->mlx_wind, 17, 0L,hook_destroy, mlx_all);
	
	if (nb_cmplx_C)
	{
		
		if(start_juliaa(mlx_all, size_wind, nb_cmplx_C) == -1)
			return (-1);
	}
	else 
	{
		if(start_mandelbrott(mlx_all, size_wind) == -1)
			return (-1);
	}
	mlx_loop(mlx_all->mlx);
	return (1);
}

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

/*
TO DO LIST

- Gestion des couleurs pour un meilleur rendu
- Gestion des segfault ou leaks en sortie de programme
- Gestion et comprehension du hook et de son utilite / utilisation
- Gestion des images (generer de nouvelle images quand il y a un zoom ou que je vais devoir me deplacer dans ma fractale)
- 


*/